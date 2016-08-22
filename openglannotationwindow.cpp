
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


GLuint      texture[1];

OpenGLAnnotationWindow::OpenGLAnnotationWindow(QWidget *parent) : QOpenGLWidget(parent)
{

}

void OpenGLAnnotationWindow::mousePressEvent(QMouseEvent *e)
{
  QPointF  pt = this->mapFromGlobal(QCursor::pos());
  int width = this->width();
  int height = this->height();
  vec_vertices.push_back(glm::vec3((pt.x()/width*2)-1, (pt.y()/height*(-2))+1, 0));
    update();
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

        // Load cube.png image
        QOpenGLTexture * texture = new QOpenGLTexture(QImage(filepath).mirrored());

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





    glPolygonMode(GL_BACK,GL_QUADS);
 //   glDrawArrays(GL_QUADS, 0, background.size());


    texture->bind();

    glBegin(GL_QUADS);
        // Front Face
        glTexCoord2f(0.0f, 0.0f); glVertex3f(-1.0f, -1.0f,  1.0f);  // Bottom Left Of The Texture and Quad
        glTexCoord2f(1.0f, 0.0f); glVertex3f( 1.0f, -1.0f,  1.0f);  // Bottom Right Of The Texture and Quad
        glTexCoord2f(1.0f, 1.0f); glVertex3f( 1.0f,  1.0f,  1.0f);  // Top Right Of The Texture and Quad
        glTexCoord2f(0.0f, 1.0f); glVertex3f(-1.0f,  1.0f,  1.0f);  // Top Left Of The Texture and Quad
        // Back Face
        glTexCoord2f(1.0f, 0.0f); glVertex3f(-1.0f, -1.0f, -1.0f);  // Bottom Right Of The Texture and Quad
        glTexCoord2f(1.0f, 1.0f); glVertex3f(-1.0f,  1.0f, -1.0f);  // Top Right Of The Texture and Quad
        glTexCoord2f(0.0f, 1.0f); glVertex3f( 1.0f,  1.0f, -1.0f);  // Top Left Of The Texture and Quad
        glTexCoord2f(0.0f, 0.0f); glVertex3f( 1.0f, -1.0f, -1.0f);  // Bottom Left Of The Texture and Quad
        // Top Face
        glTexCoord2f(0.0f, 1.0f); glVertex3f(-1.0f,  1.0f, -1.0f);  // Top Left Of The Texture and Quad
        glTexCoord2f(0.0f, 0.0f); glVertex3f(-1.0f,  1.0f,  1.0f);  // Bottom Left Of The Texture and Quad
        glTexCoord2f(1.0f, 0.0f); glVertex3f( 1.0f,  1.0f,  1.0f);  // Bottom Right Of The Texture and Quad
        glTexCoord2f(1.0f, 1.0f); glVertex3f( 1.0f,  1.0f, -1.0f);  // Top Right Of The Texture and Quad
        // Bottom Face
        glTexCoord2f(1.0f, 1.0f); glVertex3f(-1.0f, -1.0f, -1.0f);  // Top Right Of The Texture and Quad
        glTexCoord2f(0.0f, 1.0f); glVertex3f( 1.0f, -1.0f, -1.0f);  // Top Left Of The Texture and Quad
        glTexCoord2f(0.0f, 0.0f); glVertex3f( 1.0f, -1.0f,  1.0f);  // Bottom Left Of The Texture and Quad
        glTexCoord2f(1.0f, 0.0f); glVertex3f(-1.0f, -1.0f,  1.0f);  // Bottom Right Of The Texture and Quad
        // Right face
        glTexCoord2f(1.0f, 0.0f); glVertex3f( 1.0f, -1.0f, -1.0f);  // Bottom Right Of The Texture and Quad
        glTexCoord2f(1.0f, 1.0f); glVertex3f( 1.0f,  1.0f, -1.0f);  // Top Right Of The Texture and Quad
        glTexCoord2f(0.0f, 1.0f); glVertex3f( 1.0f,  1.0f,  1.0f);  // Top Left Of The Texture and Quad
        glTexCoord2f(0.0f, 0.0f); glVertex3f( 1.0f, -1.0f,  1.0f);  // Bottom Left Of The Texture and Quad
        // Left Face
        glTexCoord2f(0.0f, 0.0f); glVertex3f(-1.0f, -1.0f, -1.0f);  // Bottom Left Of The Texture and Quad
        glTexCoord2f(1.0f, 0.0f); glVertex3f(-1.0f, -1.0f,  1.0f);  // Bottom Right Of The Texture and Quad
        glTexCoord2f(1.0f, 1.0f); glVertex3f(-1.0f,  1.0f,  1.0f);  // Top Right Of The Texture and Quad
        glTexCoord2f(0.0f, 1.0f); glVertex3f(-1.0f,  1.0f, -1.0f);  // Top Left Of The Texture and Quad
    glEnd();

    glDisable(GL_TEXTURE_2D);

    if(vec_vertices.size() > 0)
    {
 //   VBO2.allocate(vec_vertices.data(), sizeof(glm::vec3)*vec_vertices.size());

  // glDrawArrays(GL_POINTS, 0, vec_vertices.size());

    glBegin(GL_POINTS);

        for(int i = 0; i < vec_vertices.size();++i)
        {
           glColor3f(1,0,0);
           glVertex3f(vec_vertices[i].x,vec_vertices[i].y,vec_vertices[i].z);
           glColor4f(1,1,1,1);
        }
        glEnd();

    }

    glEnable(GL_TEXTURE_2D);

}


void OpenGLAnnotationWindow::resizeGL(int w, int h)
{
   glViewport(0, 0, w, h);
}

void OpenGLAnnotationWindow::draw()
{
 bdraw = true;
 update();
}

void OpenGLAnnotationWindow::next()
{/*
if(count < model.vec_vertices.size()-1)
{


    model.vec_color[count] = glm::vec4(1,1,1,0.3);
    ++count;
    model.vec_color[count] = glm::vec4(1,0,0,1);
    model.vec_vertices[count].z = -1;
    update();
}
else
{
    for(int i = 0; i < model.vec_color.size(); ++i)
    {
        model.vec_color[i]=glm::vec4(0,1,0,1);
    }
    update();
} */
}


GLuint OpenGLAnnotationWindow::LoadShaders(const char * vertex_file_path,const char * fragment_file_path){

    // Create the shaders
    GLuint VertexShaderID = glCreateShader(GL_VERTEX_SHADER);
    GLuint FragmentShaderID = glCreateShader(GL_FRAGMENT_SHADER);

    // Read the Vertex Shader code from the file
    std::string VertexShaderCode;
    std::ifstream VertexShaderStream(vertex_file_path, std::ios::in);
    if(VertexShaderStream.is_open()){
        std::string Line = "";
        while(getline(VertexShaderStream, Line))
            VertexShaderCode += "\n" + Line;
        VertexShaderStream.close();
    }else{
        printf("Impossible to open %s. Are you in the right directory ? Don't forget to read the FAQ !\n", vertex_file_path);
        getchar();
        return 0;
    }

    // Read the Fragment Shader code from the file
    std::string FragmentShaderCode;
    std::ifstream FragmentShaderStream(fragment_file_path, std::ios::in);
    if(FragmentShaderStream.is_open()){
        std::string Line = "";
        while(getline(FragmentShaderStream, Line))
            FragmentShaderCode += "\n" + Line;
        FragmentShaderStream.close();
    }

    GLint Result = GL_FALSE;
    int InfoLogLength;


    // Compile Vertex Shader
    printf("Compiling shader : %s\n", vertex_file_path);
    char const * VertexSourcePointer = VertexShaderCode.c_str();
    glShaderSource(VertexShaderID, 1, &VertexSourcePointer , NULL);
    glCompileShader(VertexShaderID);

    // Check Vertex Shader
    glGetShaderiv(VertexShaderID, GL_COMPILE_STATUS, &Result);
    glGetShaderiv(VertexShaderID, GL_INFO_LOG_LENGTH, &InfoLogLength);
    if ( InfoLogLength > 0 ){
        std::vector<char> VertexShaderErrorMessage(InfoLogLength+1);
        glGetShaderInfoLog(VertexShaderID, InfoLogLength, NULL, &VertexShaderErrorMessage[0]);
        printf("%s\n", &VertexShaderErrorMessage[0]);
    }



    // Compile Fragment Shader
    printf("Compiling shader : %s\n", fragment_file_path);
    char const * FragmentSourcePointer = FragmentShaderCode.c_str();
    glShaderSource(FragmentShaderID, 1, &FragmentSourcePointer , NULL);
    glCompileShader(FragmentShaderID);

    // Check Fragment Shader
    glGetShaderiv(FragmentShaderID, GL_COMPILE_STATUS, &Result);
    glGetShaderiv(FragmentShaderID, GL_INFO_LOG_LENGTH, &InfoLogLength);
    if ( InfoLogLength > 0 ){
        std::vector<char> FragmentShaderErrorMessage(InfoLogLength+1);
        glGetShaderInfoLog(FragmentShaderID, InfoLogLength, NULL, &FragmentShaderErrorMessage[0]);
        printf("%s\n", &FragmentShaderErrorMessage[0]);
    }



    // Link the program
    printf("Linking program\n");
    GLuint ProgramID = glCreateProgram();
    glAttachShader(ProgramID, VertexShaderID);
    glAttachShader(ProgramID, FragmentShaderID);
    glLinkProgram(ProgramID);

    // Check the program
    glGetProgramiv(ProgramID, GL_LINK_STATUS, &Result);
    glGetProgramiv(ProgramID, GL_INFO_LOG_LENGTH, &InfoLogLength);
    if ( InfoLogLength > 0 ){
        std::vector<char> ProgramErrorMessage(InfoLogLength+1);
        glGetProgramInfoLog(ProgramID, InfoLogLength, NULL, &ProgramErrorMessage[0]);
        printf("%s\n", &ProgramErrorMessage[0]);
    }


    glDetachShader(ProgramID, VertexShaderID);
    glDetachShader(ProgramID, FragmentShaderID);

    glDeleteShader(VertexShaderID);
    glDeleteShader(FragmentShaderID);

    return ProgramID;
}




