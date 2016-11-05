#include "openglwindow.h"
#include <QOpenGLWidget>
#include <iostream>
#include <glm/glm.hpp>
#include <stdio.h>
#include <fstream>
#include <QOpenGLShaderProgram>
#include <QOpenGLTexture>







OpenGLWindow::OpenGLWindow(QWidget *parent) : QOpenGLWidget(parent)
{
 start = true;

}

void OpenGLWindow::initializeGL()
{
    initializeOpenGLFunctions();
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glEnable( GL_BLEND );
    glClearColor(0.0,0.0,0.0,1.0);

    //glEnable(GL_DEPTH_TEST);
    glPointSize(4);
    glIsEnabled(true);

   // programID = LoadShaders( "..\\AFMA\\vertexshader.vert", "..\\AFMA\\fragmentshader.frag" );
   // glUseProgram(programID);



    numberOfVertices = model.vec_vertices.size();

    numberOfIndices = model.vec_indices.size();




    VAO.create();
    VAO.bind();
    VBO.create();
    VBO.bind();
    VBOColor.create();
    VBOColor.bind();

    IBO.create();
    IBO.bind();

    VBOTexCords.create();
    VBOTexCords.bind();


    glBegin(GL_QUADS);
        // Front Face
        glTexCoord2f(0.0f, 0.0f); glVertex3f(-1.0f, -1.0f, 1.0f);  // Bottom Left Of The Texture and Quad
        glTexCoord2f(1.0f, 0.0f); glVertex3f( 1.0f, -1.0f, 1.0f);  // Bottom Right Of The Texture and Quad
        glTexCoord2f(1.0f, 1.0f); glVertex3f( 1.0f,  1.0f, 1.0f);  // Top Right Of The Texture and Quad
        glTexCoord2f(0.0f, 1.0f); glVertex3f(-1.0f,  1.0f, 1.0f);  // Top Left Of The Texture and Quad

    glEnd();

    glGenBuffers(1, &VertexBufferId); // Buffer erzeugen
    glGenBuffers(1, &elementbuffer);

}

void OpenGLWindow::paintGL()
{
    if(bdraw ==true && line == false)
    {
    m_shader.removeAllShaders();

        m_shader.addShaderFromSourceFile(QOpenGLShader::Vertex, "..\\AFMA\\modelvertexshader.vert");
        m_shader.addShaderFromSourceFile(QOpenGLShader::Fragment, "..\\AFMA\\modelfragmentshader.frag");

        m_shader.link();
        m_shader.bind();

        VBO.bind();
        VBO.allocate(model.vec_vertices.data(), sizeof(glm::vec3)*numberOfVertices);
        m_shader.enableAttributeArray(0);
        m_shader.setAttributeBuffer( 0, GL_FLOAT, 0, 3 );




        VBOColor.bind();
        VBOColor.allocate(model.vec_color.data(), sizeof(glm::vec4)*model.vec_color.size());
        m_shader.enableAttributeArray(1);
        m_shader.setAttributeBuffer( 1, GL_FLOAT, 0, 4 );


glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);


glPolygonMode(GL_FRONT,GL_POINTS);

glDrawArrays(GL_POINTS, 0, numberOfVertices);
VBO.release();
VBOColor.release();

    }


   else if(bdraw ==true && line == true)
    {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_POLYGON_MODE);
        m_shader.removeAllShaders();

        m_shader.addShaderFromSourceFile(QOpenGLShader::Vertex, "..\\AFMA\\annotationvertexshader.vert");
        m_shader.addShaderFromSourceFile(QOpenGLShader::Fragment, "..\\AFMA\\annotationfragmentshader.frag");

        m_shader.link();
        m_shader.bind();







       std::vector<glm::vec2> vec_tex;

        for(unsigned int i = 0; i < model.vec_vertices.size(); ++i)
        {
            vec_tex.push_back(glm::vec2((model.vec_changed[i].x+1)/2, (model.vec_changed[i].y+1)/2));
        }

        VBOTexCords.bind();
        VBOTexCords.allocate(vec_tex.data(), sizeof(glm::vec2)*vec_tex.size());
        m_shader.enableAttributeArray(1);
        m_shader.setAttributeBuffer(1, GL_FLOAT,0,2);
        VBOTexCords.release();

         QOpenGLTexture * texture = new QOpenGLTexture(textureImage.mirrored());
        // Set nearest filtering mode for texture minification
        texture->setMinificationFilter(QOpenGLTexture::Nearest);

        // Set bilinear filtering mode for texture magnification
        texture->setMagnificationFilter(QOpenGLTexture::Linear);

        // Wrap texture coordinates by repeating
        // f.ex. texture coordinate (1.1, 1.2) is same as (0.1, 0.2)
        texture->setWrapMode(QOpenGLTexture::ClampToBorder);


    // Give our vertices to OpenGL.

        glEnable(GL_TEXTURE_2D);



         // ID des Vertex-Buffer-Objekts

        VBO.bind();
        VBO.allocate(model.vec_vertices.data(), sizeof(glm::vec3)*numberOfVertices);

        m_shader.enableAttributeArray(0);
        m_shader.setAttributeBuffer( 0, GL_FLOAT, 0, 3 );

        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, elementbuffer);

       glBufferData(GL_ELEMENT_ARRAY_BUFFER, model.vec_indices_ushort.size() *sizeof(unsigned short)  , model.vec_indices_ushort.data(), GL_DYNAMIC_DRAW);

       //sizeof(glm::vec3)*model.vec_indices.size()


    texture->bind();


glPolygonMode(GL_FRONT, GL_TRIANGLES);

glDrawElements(GL_TRIANGLES, 184*3, GL_UNSIGNED_SHORT, (void*)0);





VBO.release();
glDeleteBuffers(1,&elementbuffer);
    }









}

void OpenGLWindow::resizeGL(int w, int h)
{
   glViewport(0, 0, w, h);
}

void OpenGLWindow::draw()
{
 bdraw = true;
 update();
}

void OpenGLWindow::next()
{


if(count < model.vec_vertices.size()-1)
{
    model.vec_color[count] = glm::vec4(1,1,1,0.1);
    ++count;
    model.vec_color[count] = glm::vec4(1,0,0,1);
    update();
}
else
{
    ++count;
    for(unsigned int i = 0; i < model.vec_color.size(); ++i)
    {
        model.vec_color[i]=glm::vec4(0,1,0,1);
    }
    update();
}
}

void OpenGLWindow::undoAnnotation()
{
    count = 0;
   model.vec_vertices = model.vec_vertices_base;
   model.vec_color = model.vec_color_base;
   model.vec_color[0] = glm::vec4(1,0,0, 0.3f);
}

