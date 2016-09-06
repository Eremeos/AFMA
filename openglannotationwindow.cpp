
#include "openglannotationwindow.h"

#include <QOpenGLWidget>
#include <QOpenGLVertexArrayObject>
#include <iostream>
#include <glm/glm.hpp>
#include <stdio.h>
#include <fstream>
#include <QMouseEvent>
#include <QOpenGLBuffer>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <QOpenGLTexture>




OpenGLAnnotationWindow::OpenGLAnnotationWindow(QWidget *parent) : QOpenGLWidget(parent)
{

}

void OpenGLAnnotationWindow::mousePressEvent(QMouseEvent *e)
{
    if(vec_vertices.size() < ogl->model.vec_vertices.size())
    {
  QPointF  pt = this->mapFromGlobal(QCursor::pos());
  int width = this->width();
  int height = this->height();
  vec_vertices.push_back(glm::vec3((pt.x()/width*2)-1, (pt.y()/height*(-2))+1, ogl->model.vec_vertices[vec_vertices.size()].z));
    update();
   ogl->next();
   for(int i = 0; i < ogl->model.vec_doubled_points.size(); ++i)
   {
       if(ogl->count == ogl->model.vec_doubled_points[i].x)
       {
           vec_vertices.push_back(vec_vertices[ogl->model.vec_doubled_points[i].y]);
           ogl->next();
           std::cout << ogl->count<< endl;
       }
   }
    }
}


void OpenGLAnnotationWindow::initializeGL()
{

    initializeOpenGLFunctions();
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glEnable( GL_BLEND );
    glClearColor(0.0,0.0,0.0,1.0);

    //glEnable(GL_DEPTH_TEST);
    glPointSize(4);
    glIsEnabled(true);

  //  programID = LoadShaders( "..\\AFMA\\vertexshader.vert", "..\\AFMA\\fragmentshader.frag" );
  //  glUseProgram(programID);


 /*   m_shader.addShaderFromSourceFile(QOpenGLShader::Vertex, "..\\AFMA\\annotationvertexshader.vert");
    m_shader.addShaderFromSourceFile(QOpenGLShader::Fragment, "..\\AFMA\\annotationfragmentshader.frag");

   m_shader.link();
   m_shader.bind(); */


    background_VAO.create();
    background_VAO.bind();
    background.push_back(glm::vec3(-1.0f, 1.0f, 0.0f));
    background.push_back(glm::vec3(-1.0f, -1.0f, 0.0f));
    background.push_back(glm::vec3(1.0f,  -1.0f, 0.0f));
    background.push_back(glm::vec3(1.0f,  1.0f, 0.0f));


    tex.push_back(glm::vec2(-1.0f, 1.0f));
    tex.push_back(glm::vec2(-1.0f, -1.0f));
    tex.push_back(glm::vec2(1.0f,  -1.0f));
    tex.push_back(glm::vec2(1.0f,  1.0f));

    // Generate 1 buffer, put the resulting identifier in vertexbuffer
  VBO.create();

    // The following commands will talk about our 'vertexbuffer' buffer
  VBO.bind();


  VBO2.create();
  VBO2.bind();


}

void OpenGLAnnotationWindow::paintGL()
{
        if(filepath != NULL)
        {
        // Load cube.png image
        QOpenGLTexture * texture = new QOpenGLTexture(textureImage.mirrored());

        // Set nearest filtering mode for texture minification
        texture->setMinificationFilter(QOpenGLTexture::Nearest);

        // Set bilinear filtering mode for texture magnification
        texture->setMagnificationFilter(QOpenGLTexture::Linear);

        // Wrap texture coordinates by repeating
        // f.ex. texture coordinate (1.1, 1.2) is same as (0.1, 0.2)
        texture->setWrapMode(QOpenGLTexture::Repeat);

        texture->bind();

    // Give our vertices to OpenGL.

        glEnable(GL_TEXTURE_2D);



        VBO.allocate(background.data(), sizeof(glm::vec3)*background.size());




        VBO.bind();
 /*     m_shader.enableAttributeArray(0);
      m_shader.setAttributeBuffer( 0, GL_FLOAT, 0, 3 );


      m_shader.enableAttributeArray(1);
      m_shader.setAttributeBuffer(1, GL_FLOAT, 0, 2);

      */


    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);





    glPolygonMode(GL_FRONT,GL_QUADS);
 //   glDrawArrays(GL_QUADS, 0, background.size());


    texture->bind();

    glBegin(GL_QUADS);
        // Front Face
        glTexCoord2f(0.0f, 0.0f); glVertex3f(-1.0f, -1.0f,  1.0f);  // Bottom Left Of The Texture and Quad
        glTexCoord2f(1.0f, 0.0f); glVertex3f( 1.0f, -1.0f,  1.0f);  // Bottom Right Of The Texture and Quad
        glTexCoord2f(1.0f, 1.0f); glVertex3f( 1.0f,  1.0f,  1.0f);  // Top Right Of The Texture and Quad
        glTexCoord2f(0.0f, 1.0f); glVertex3f(-1.0f,  1.0f,  1.0f);  // Top Left Of The Texture and Quad

    glEnd();

    glDisable(GL_TEXTURE_2D);

    if(vec_vertices.size() > 0)
    {
 //   VBO2.allocate(vec_vertices.data(), sizeof(glm::vec3)*vec_vertices.size());

  // glDrawArrays(GL_POINTS, 0, vec_vertices.size());

    glBegin(GL_POINTS);

        for(unsigned int i = 0; i < vec_vertices.size();++i)
        {
           glColor3f(1,0,0);
           glVertex3f(vec_vertices[i].x,vec_vertices[i].y,vec_vertices[i].z);
           glColor4f(1,1,1,1);
        }
        glEnd();

    }
ogl->draw();
        }
}


void OpenGLAnnotationWindow::resizeGL(int w, int h)
{
   glViewport(0, 0, w, h);
}

