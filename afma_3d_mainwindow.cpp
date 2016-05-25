#include "afma_3d_mainwindow.h"
#include "ui_afma_3d_mainwindow.h"

AFMA_3D_MainWindow::AFMA_3D_MainWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AFMA_3D_MainWindow)
{
    ui->setupUi(this);
}

AFMA_3D_MainWindow::~AFMA_3D_MainWindow()
{
    delete ui;
}
