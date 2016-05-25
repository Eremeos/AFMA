#include "facecomponent2d.h"
#include <stdio.h>


FaceComponent2D::FaceComponent2D()
{

}

FaceComponent2D::FaceComponent2D(cv::Rect rectComponent)
{
    setComponent(rectComponent);
}

void FaceComponent2D::setComponent(cv::Rect newComponent)
{
    m_Component = newComponent;
}

cv::Rect FaceComponent2D::getComponent()
{

    return m_Component;

}
