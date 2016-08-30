#ifndef OPENGLANNOTATIONWINDOW_H
#define OPENGLANNOTATIONWINDOW_H


#include <QWidget>
#include <QOpenGLWidget>
#include <QOpenGLFunctions>
#include <QGLWidget>
#include <QMouseEvent>
#include <glm/vec3.hpp>
#include <facemodelcandide.h>
#include <QOpenGLVertexArrayObject>
#include <QOpenGLBuffer>
#include <QOpenGLShaderProgram>
#include <openglwindow.h>

class OpenGLAnnotationWindow : public QOpenGLWidget, protected QOpenGLFunctions
{
    Q_OBJECT
public:
    explicit OpenGLAnnotationWindow(QWidget *parent = 0);
    QPointF pt;
    void initializeGL();
    void paintGL();
    void resizeGL(int w, int h);
    int numberOfVertices;
    int numberOfIndices;
    std::vector<glm::vec3> vec_vertices;
    OpenGLWindow *ogl;
    GLuint programID;



    void draw();
    void next();
    bool bdraw = false;

    QOpenGLVertexArrayObject background_VAO;
    QOpenGLVertexArrayObject drawing_VAO;
    QOpenGLBuffer VBO;
    QOpenGLBuffer VBO2;
    QOpenGLBuffer Texture;
    std::vector<glm::vec3> background;
    std::vector<glm::vec2> tex;
    QOpenGLShaderProgram m_shader;
    QString filepath;
    QImage textureImage;


signals:

public slots:

        void mousePressEvent(QMouseEvent * e);

};

#endif // OPENGLANNOTATIONWINDOW_H
