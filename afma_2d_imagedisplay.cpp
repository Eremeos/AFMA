#include "afma_2d_imagedisplay.h"
#include "utility2d.h"
#include "afma_2d_mainwindow.h"



#include <QPointF>

AFMA_2D_ImageDisplay::AFMA_2D_ImageDisplay(QWidget *parent) :
    QGraphicsView(parent)
{

}

void AFMA_2D_ImageDisplay::mousePressEvent(QMouseEvent * e)
{
    pt = mapToScene(e->pos());
    double rad = 1;
    scene()->addEllipse(pt.x()-rad, pt.y()-rad, rad*3.0, rad*3.0,
        QPen(Qt::red), QBrush(Qt::SolidPattern));
    vec_pt.push_back(pt);
}
