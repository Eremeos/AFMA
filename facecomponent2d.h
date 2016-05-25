#ifndef FACECOMPONENT2D_H
#define FACECOMPONENT2D_H
#include <opencv2/core/core.hpp>
#include <stdio.h>


class FaceComponent2D
{
public:
    FaceComponent2D();
    FaceComponent2D(cv::Rect rectComponent);

    void setComponent(cv::Rect);
    cv::Rect getComponent();
private:
    cv::Rect m_Component;
};

#endif // FACECOMPONENT2D_H
