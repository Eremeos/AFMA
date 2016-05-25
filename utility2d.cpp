#include "utility2d.h"
#include <QColor>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv/cv.h>
#include <opencv2/objdetect/objdetect.hpp>
#include <stdio.h>



Utility2D::Utility2D()
{

}

cv::Mat Utility2D::convertToGreyScale(cv::Mat newImage)
{
    for(int i = 0; i < newImage.rows; ++i)
    {
        for(int j = 0; j < newImage.cols; ++j)
        {      int gray = (newImage.at<cv::Vec3b>(i,j)[0]+newImage.at<cv::Vec3b>(i,j)[1]+newImage.at<cv::Vec3b>(i,j)[2]) /3;
               newImage.at<cv::Vec3b>(i,j)[0] =gray;
               newImage.at<cv::Vec3b>(i,j)[1] =gray;
               newImage.at<cv::Vec3b>(i,j)[2] =gray;
        }
    }

   return newImage;
}

std::vector<cv::Rect> Utility2D::findFace(cv::Mat newImage)
{
    cv::CascadeClassifier face_cascade;
    face_cascade.load("..\\AFMA\\haarcascades\\haarcascade_frontalface_default.xml" );


    //Face Detection

    std::vector<cv::Rect> faces;
    face_cascade.detectMultiScale( newImage, faces, 1.1, 2, 0|CV_HAAR_SCALE_IMAGE, cv::Size(50, 50) );

    return faces;
}

std::vector<cv::Rect> Utility2D::findEye(cv::Mat newImage)
{
    cv::CascadeClassifier eye_cascade;
    eye_cascade.load("..\\AFMA\\haarcascades\\haarcascade_eye.xml" );

    //Eye Detection
    std::vector<cv::Rect> eyes;
    eye_cascade.detectMultiScale( newImage, eyes, 1.1, 2, 0|CV_HAAR_SCALE_IMAGE, cv::Size(25, 25) );

    return eyes;
}

std::vector<cv::Rect> Utility2D::findMouth(cv::Mat newImage)
{
    cv::CascadeClassifier mouth_cascade;
    mouth_cascade.load("..\\AFMA\\haarcascades\\haarcascade_smile.xml" );

    //Eye Detection
    std::vector<cv::Rect> mouth;
    mouth_cascade.detectMultiScale( newImage, mouth, 1.1, 2, 0|CV_HAAR_SCALE_IMAGE, cv::Size(25, 25) );

    return mouth;
}

QImage Utility2D::fromOpenCVToQImage(cv::Mat img)
{
     cv::Mat temp; // make the same cv::Mat
     cvtColor(img, temp,CV_BGR2RGB); // cvtColor Makes a copt, that what i need
     QImage dest((const uchar *) temp.data, temp.cols, temp.rows, temp.step, QImage::Format_RGB888);
     dest.bits(); // enforce deep copy, see documentation
     // of QImage::QImage ( const uchar * data, int width, int height, Format format )
     return dest;
}

cv::Mat Utility2D::fromQImageToOpenCV(QImage img)
{
    cv::Mat tmp(img.height(),img.width(),CV_8UC3,(uchar*)img.bits(),img.bytesPerLine());
    cv::Mat result; // deep copy just in case (my lack of knowledge with open cv)
    cvtColor(tmp, result,CV_BGR2RGB);
    return result;
}

void Utility2D::drawRect(cv::Mat newImage, FaceComponent2D component)
{
        cv::Rect rec = component.getComponent();
        cv::rectangle(newImage, rec,cv::Scalar(0, 0, 255 ), 1, 8, 0 );

}

void Utility2D::drawEllipse(cv::Mat newImage, FaceComponent2D component)
{
        cv::Rect rec = component.getComponent();
        cv::Point center( rec.x + rec.width*0.5, rec.y + rec.height*0.5 );
        cv::ellipse( newImage, center, cv::Size( rec.width*0.5, rec.height*0.5), 0, 0, 360, cv::Scalar( 255, 0, 0 ), 1, 8, 0 );

}

void Utility2D::generateFaceModel(FaceModel2D &faceModel, cv::Mat ima)
{
    std::vector<cv::Rect> faces = Utility2D::findFace(ima);
    std::vector<cv::Rect> eyes = Utility2D::findEye(ima);
    std::vector<cv::Rect> mouth = Utility2D::findMouth(ima);
    faceModel.setFace(faces[0]);
    faceModel.setLeftEye(eyes[0]);
    faceModel.setRightEye(eyes[1]);
    faceModel.setMouth(mouth[0]);
}


cv::Mat Utility2D::setAllPixels(cv::Mat newImage, int r, int g, int b)
{
    for(int i = 0; i < newImage.rows; ++i)
    {
        for(int j = 0; j < newImage.cols; ++j)
        {
               newImage.at<cv::Vec3b>(i,j)[0] =b;
               newImage.at<cv::Vec3b>(i,j)[1] =g;
               newImage.at<cv::Vec3b>(i,j)[2] =r;
        }
    }
    return newImage;
}
