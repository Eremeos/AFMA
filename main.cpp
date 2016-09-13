
#include "afma_2d_mainwindow.h"
#include <QApplication>


using namespace cv;


int main(int argc, char *argv[])
{

    QApplication a(argc, argv);

    AFMA_2D_MainWindow window;

    window.exec();


    return a.exec();
}
