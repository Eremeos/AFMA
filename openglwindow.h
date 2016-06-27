#ifndef OPENGLWINDOW_H
#define OPENGLWINDOW_H

#include <QWidget>
#include <GL/glew.h>
#include <QOpenGLWidget>
#include <QOpenGLFunctions>
#include <QGLWidget>

class OpenGLWindow : public QOpenGLWidget, protected QOpenGLFunctions
{
    Q_OBJECT
public:
    explicit OpenGLWindow(QWidget *parent = 0);
    void initializeGL();
    void paintGL();
    void resizeGL(int w, int h);
    bool start;






signals:

public slots:
};

#endif // OPENGLWINDOW_H
