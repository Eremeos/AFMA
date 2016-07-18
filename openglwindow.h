#ifndef OPENGLWINDOW_H
#define OPENGLWINDOW_H

#include <QWidget>
#include <QOpenGLWidget>
#include <QOpenGLFunctions>
#include <QGLWidget>
#include <QMouseEvent>
#include <glm/vec3.hpp>
#include <facemodelcandide.h>

class OpenGLWindow : public QOpenGLWidget, protected QOpenGLFunctions
{
    Q_OBJECT
public:
    explicit OpenGLWindow(QWidget *parent = 0);
    void initializeGL();
    void paintGL();
    void resizeGL(int w, int h);
    bool start;
    void draw();
    void next();
    bool bdraw = false;
    std::vector<QPointF> vec_pt;
    int numberOfVertices;
    int numberOfIndices;
    int count = 0;
    FacemodelCandide model;
    GLuint programID;

    GLuint myBufferID;
    GLuint colorbuffer;

    GLuint LoadShaders(const char * vertex_file_path,const char * fragment_file_path);

    void initializeVertices();
    void initializeIndices();
    void initializeColor();


signals:

public slots:
};

#endif // OPENGLWINDOW_H
