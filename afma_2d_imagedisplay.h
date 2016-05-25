#ifndef AFMA_2D_IMAGEDISPLAY_H
#define AFMA_2D_IMAGEDISPLAY_H

#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsEllipseItem>
#include <QMouseEvent>



class AFMA_2D_ImageDisplay : public QGraphicsView
{
    Q_OBJECT
public:
    explicit AFMA_2D_ImageDisplay(QWidget *parent = 0);
    QPointF pt;
    std::vector<QPointF> vec_pt;

signals:

public slots:
    void mousePressEvent(QMouseEvent * e);
    // void mouseReleaseEvent(QMouseEvent * e);
    // void mouseDoubleClickEvent(QMouseEvent * e);
    // void mouseMoveEvent(QMouseEvent * e);
private:
};

#endif // AFMA_2D_IMAGEDISPLAY_H
