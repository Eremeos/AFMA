#include "afma_mainwindow.h"
#include <QApplication>


using namespace cv;


int main(int argc, char *argv[])
{

    QApplication a(argc, argv);
    AFMA_MainWindow w;
    w.show();

    return a.exec();
}
