#include "afma_mainwindow.h"
#include "ui_afma_mainwindow.h"
#include "afma_2d_mainwindow.h"
#include "afma_3d_mainwindow.h"



AFMA_MainWindow::AFMA_MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::AFMA_MainWindow)
{
    ui->setupUi(this);
}

AFMA_MainWindow::~AFMA_MainWindow()
{
    delete ui;
}


void AFMA_MainWindow::on_psBtn_2D_clicked()
{
    m_window2D.showMaximized();
}

void AFMA_MainWindow::on_psBtn_3D_clicked()
{
   m_window3D.showMaximized();
}
