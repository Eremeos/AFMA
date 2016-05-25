#include "facemodel2d.h"

FaceModel2D::FaceModel2D()
{

}

FaceComponent2D FaceModel2D::getleftEye() const
{
    return m_leftEye;
}

void FaceModel2D::setLeftEye(const FaceComponent2D &leftEye)
{
    m_leftEye = leftEye;
}

FaceComponent2D FaceModel2D::getrightEye() const
{
    return m_rightEye;
}

void FaceModel2D::setRightEye(const FaceComponent2D &rightEye)
{
    m_rightEye = rightEye;
}

FaceComponent2D FaceModel2D::getMouth() const
{
    return m_Mouth;
}

void FaceModel2D::setMouth(const FaceComponent2D &Mouth)
{
    m_Mouth = Mouth;
}

FaceComponent2D FaceModel2D::getFace() const
{
    return m_Face;
}

void FaceModel2D::setFace(const FaceComponent2D &Face)
{
    m_Face = Face;
}
