#ifndef AFMA_3D_MAINWINDOW_H
#define AFMA_3D_MAINWINDOW_H

#include <QDialog>

namespace Ui {
class AFMA_3D_MainWindow;
}

class AFMA_3D_MainWindow : public QDialog
{
    Q_OBJECT

public:
    explicit AFMA_3D_MainWindow(QWidget *parent = 0);
    ~AFMA_3D_MainWindow();

private:
    Ui::AFMA_3D_MainWindow *ui;
};

#endif // AFMA_3D_MAINWINDOW_H
