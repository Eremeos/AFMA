#ifndef OPENGLANNOTATIONWINDOW_H
#define OPENGLANNOTATIONWINDOW_H


#include <QWidget>
#include <QOpenGLWidget>
#include <QOpenGLFunctions>
#include <QGLWidget>
#include <QMouseEvent>
#include <glm/vec3.hpp>
#include <facemodelcandide.h>


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

    GLuint programID;

    GLuint myBufferID;
    GLuint colorbuffer;

    GLuint LoadShaders(const char * vertex_file_path,const char * fragment_file_path);

    void draw();
    void next();
    bool bdraw = false;

signals:

public slots:

        void mousePressEvent(QMouseEvent * e);

};

#endif // OPENGLANNOTATIONWINDOW_H
