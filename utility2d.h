#ifndef UTILITY2D_H
#define UTILITY2D_H
#include <glm/glm.hpp>
#include <QImage>
#include <opencv2/core/core.hpp>
#include <stdio.h>
#include <facemodel2d.h>
#include <facecomponent2d.h>
//Library for 2D Functions

class Utility2D
{
public:
    Utility2D();
    static cv::Mat setAllPixels(cv::Mat newImage, int r, int g, int b);
    static cv::Mat convertToGreyScale(cv::Mat newImage);
    static std::vector<cv::Rect> findFace(cv::Mat newImage);
    static std::vector<cv::Rect> findEye(cv::Mat newImage);
    static std::vector<cv::Rect> findMouth(cv::Mat newImage);
    static QImage fromOpenCVToQImage(cv::Mat img);
    static cv::Mat fromQImageToOpenCV(QImage img);
    static void drawRect(cv::Mat newImage, FaceComponent2D component);
    static void drawEllipse(cv::Mat newImage, FaceComponent2D component);
    static void generateFaceModel(FaceModel2D &faceModel, cv::Mat ima);

    static void convert(std::vector<QPointF> &vec_points, std::vector<glm::vec3> &vec_vertices, cv::Mat ima);
};



#endif // UTILITY2D_H
