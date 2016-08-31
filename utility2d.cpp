#include "utility2d.h"
#include <QColor>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv/cv.h>
#include <opencv2/objdetect/objdetect.hpp>
#include <stdio.h>
#include <glm/glm.hpp>


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



void Utility2D::convert(std::vector<QPointF> &vec_points, std::vector<glm::vec3> &vec_vertices, cv::Mat ima)
{
 float width = ima.cols;
 float height = ima.rows;

/* for(int i = 0; i < vec_points.size();++i)
 {
    if(vec_points[i].x() > width)
    {
        width = vec_points[i].x();
    }

    if(vec_points[i].y() > height)
    {
        height = vec_points[i].y();
    }
 } */

 for(unsigned int i = 0; i < vec_points.size();++i)
 {
     vec_vertices[i].x = (vec_points[i].x()/width *2)-1;
     vec_vertices[i].y = ((vec_points[i].y()/height*(-2))+1);

 }

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
