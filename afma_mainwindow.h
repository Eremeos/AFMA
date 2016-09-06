#ifndef AFMA_MAINWINDOW_H
#define AFMA_MAINWINDOW_H

#include <QMainWindow>

#include "afma_2d_mainwindow.h"


namespace Ui {
class AFMA_MainWindow;
}

class AFMA_MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit AFMA_MainWindow(QWidget *parent = 0);
    ~AFMA_MainWindow();
    AFMA_2D_MainWindow m_window2D;

private slots:
    void on_psBtn_2D_clicked();


private:
    Ui::AFMA_MainWindow *ui;
};

#endif // AFMA_MAINWINDOW_H
