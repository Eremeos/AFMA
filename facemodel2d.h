#ifndef FACEMODEL2D_H
#define FACEMODEL2D_H
#include <facecomponent2d.h>


class FaceModel2D
{
public:
    FaceModel2D();
    FaceComponent2D getleftEye() const;

    void setLeftEye(const FaceComponent2D &leftEye);

    FaceComponent2D getrightEye() const;
    void setRightEye(const FaceComponent2D &rightEye);

    FaceComponent2D getMouth() const;
    void setMouth(const FaceComponent2D &Mouth);

    FaceComponent2D getFace() const;
    void setFace(const FaceComponent2D &Face);

private:
    FaceComponent2D m_leftEye;
    FaceComponent2D m_rightEye;
    FaceComponent2D m_Mouth;
    FaceComponent2D m_Face;




};

#endif // FACEMODEL2D_H
