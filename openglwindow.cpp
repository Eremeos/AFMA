#include "openglwindow.h"
#include <QOpenGLWidget>
#include <iostream>
#include <glm/glm.hpp>
#include <stdio.h>
#include <fstream>
#include <QOpenGLShaderProgram>







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

    m_shader.addShaderFromSourceFile(QOpenGLShader::Vertex, "..\\AFMA\\modelvertexshader.vert");
    m_shader.addShaderFromSourceFile(QOpenGLShader::Fragment, "..\\AFMA\\modelfragmentshader.frag");

    m_shader.link();
    m_shader.bind();

    numberOfVertices = model.vec_vertices.size();

    numberOfIndices = model.vec_indices.size();




    VAO.create();
    VAO.bind();
    VBO.create();
    VBO.bind();
    VBO2.create();
    VBO2.bind();

}

void OpenGLWindow::paintGL()
{
    if(bdraw ==true)
    {

     // glGenBuffers(1, &myBufferID);
     // glBindBuffer(GL_ARRAY_BUFFER, myBufferID);
     //  glVertexPointer(3, GL_FLOAT, 0, 0);
     //     glBufferData(GL_ARRAY_BUFFER, sizeof(glm::vec3)*numberOfVertices, &model.vec_vertices[0], GL_STATIC_DRAW);
      //  glVertexAttribPointer(0,3, GL_FLOAT, GL_FALSE, 0, (GLubyte *)NULL);
        VBO.bind();
        VBO.allocate(model.vec_vertices.data(), sizeof(glm::vec3)*numberOfVertices);


        m_shader.enableAttributeArray(0);

         m_shader.setAttributeBuffer( 0, GL_FLOAT, 0, 3 );


        //glGenBuffers(1, &colorbuffer);
        //glBindBuffer(GL_ARRAY_BUFFER, colorbuffer);
        //glColorPointer(3, GL_FLOAT, 0, 0);
       // glBufferData(GL_ARRAY_BUFFER, sizeof(glm::vec4)*numberOfVertices, &model.vec_color[0], GL_STATIC_DRAW);
         //  glVertexAttribPointer( 1,4,GL_FLOAT,GL_FALSE, 0,(void*)0);

        VBO2.bind();
        VBO2.allocate(model.vec_color.data(), sizeof(glm::vec3)*numberOfVertices);

        m_shader.enableAttributeArray(1);
        m_shader.setAttributeBuffer( 1, GL_FLOAT, 0, 4 );






glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);


glPolygonMode(GL_BACK,GL_POINTS);

glDrawArrays(GL_POINTS, 0, numberOfVertices);
//glDrawElements(GL_TRIANGLES, numberOfIndices, GL_UNSIGNED_INT, 0);
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
}
}


GLuint OpenGLWindow::LoadShaders(const char * vertex_file_path,const char * fragment_file_path){

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

