#ifndef FACEMODELCANDIDE_H
#define FACEMODELCANDIDE_H

#include <glm/glm.hpp>
#include <vector>
#include <facecomponent.h>

class FacemodelCandide
{
public:
    FacemodelCandide();
    void initializeVertices();
    void initializeColor();
    void initializeIndices();

    std::vector<glm::vec3> vec_vertices;
    std::vector<glm::vec3> vec_vertices_base;
    std::vector<glm::vec3> vec_changed;
    std::vector<glm::vec4> vec_color;
    std::vector<glm::vec3> vec_indices;
    std::vector<unsigned short> vec_indices_ushort;

    FaceComponent leftEyebrow;
    FaceComponent rightEyebrow;
    FaceComponent leftEye;
    FaceComponent rightEye;
    FaceComponent upperLip;
    FaceComponent lowerLip;

    void setFaceComponents();

    void upperLipraiser();

};

#endif // FACEMODELCANDIDE_H
