#ifndef AFMA_2D_MAINWINDOW_H
#define AFMA_2D_MAINWINDOW_H

#include <QDialog>
#include <opencv2/core/core.hpp>
#include <stdio.h>
#include <facemodel2d.h>
#include <facecomponent2d.h>
#include <QFileDialog>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsEllipseItem>
#include <QMouseEvent>
#include "afma_2d_imagedisplay.h"
#include <QPointF>

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
    cv::Mat m_image;
    cv::Mat m_morphed_Image;
    cv::Mat m_cropped_Component;
    cv::Mat m_displayed_Image;
    FaceModel2D m_FaceModel;
    double m_scale = 1.0;
    int m_initial_Slider_position = 50;
    std::vector<QPointF> vec_points;



private slots:

    void on_psBtn_Load_clicked();

    void on_psBtn_SetPixel_clicked();

    void setDisplayImage(cv::Mat newImage);

    void on_psButton_Initial_Image_clicked();

    void on_psBtn_FaceDet_clicked();

    void on_sld_Scale_sliderMoved(int position);


    void on_psBtn_SaveAnnotation_clicked();

    void on_psBtn_LoadProject_clicked();

    void on_psBtn_ClearAnnotation_clicked();

private:
    Ui::AFMA_2D_MainWindow *ui;
};

#endif // AFMA_2D_MAINWINDOW_H
