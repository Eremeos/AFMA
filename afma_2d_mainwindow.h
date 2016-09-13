#ifndef AFMA_2D_MAINWINDOW_H
#define AFMA_2D_MAINWINDOW_H

#include <QDialog>
#include <opencv2/core/core.hpp>
#include <stdio.h>
#include <QMainWindow>
#include <QFileDialog>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsEllipseItem>
#include <QMouseEvent>
#include <QPointF>
#include <glm/glm.hpp>
#include <animationdialog.h>
#include <QTimer>

namespace Ui {
class AFMA_2D_MainWindow;
}

class AFMA_2D_MainWindow : public QDialog
{
    Q_OBJECT

public:
    explicit AFMA_2D_MainWindow(QWidget *parent = 0);
    ~AFMA_2D_MainWindow();

    QGraphicsScene *m_scene = new QGraphicsScene();
    QString m_fileName;

    double m_scale = 1.0;
    int m_initial_Slider_position = 5;

    QImage Texture;
    AnimationDialog *dia;
    std::vector<std::vector<glm::vec3>> animationList;
    std::vector<QString> animationName;
    int timeframe = 1;

    QTimer timer;

    bool animation = false;

    bool show = false;

    unsigned int changeCount = 0;



private slots:

    void updateModel();

    void showModel();

    void drawAnnotation(std::vector<glm::vec3> pts);

    void debugMessage(QString str);


    void clearAnnotation();

    void updateAnimation();

    void on_psBtn_Load_clicked();



    void on_psBtn_SaveAnnotation_clicked();

    void on_psBtn_LoadProject_clicked();

    void on_psBtn_ClearAnnotation_clicked();


    void on_psBtn_UndoLastPoint_clicked();



    void on_psBtn_GenerateModel_clicked();

    void on_psBtn_AnnotationHelp_clicked();

    void on_psBtn_SetAnimation_clicked();

    void on_psBtn_StartAnimation_clicked();

    void on_psBtn_SafeAnimation_clicked();

    void on_sld_Time_valueChanged(int value);

    void on_psBtn_RemoveAnimation_clicked();

    void on_psBtn_Override_clicked();

private:
    Ui::AFMA_2D_MainWindow *ui;
};

#endif // AFMA_2D_MAINWINDOW_H
