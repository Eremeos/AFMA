#ifndef FACEMODELCANDIDE_H
#define FACEMODELCANDIDE_H

#include <glm/glm.hpp>
#include <vector>
#include <facecomponent.h>
#include <QString>

class FacemodelCandide
{
public:
    FacemodelCandide();
    void initializeVertices();
    void initializeColor();
    void initializeIndices();
    void initializeAnnotationText();
    void initializeDoubledPoints();
    void initializeFaceComponents();
    void setFaceComponents();

    std::vector<glm::vec3> vec_vertices;
    std::vector<glm::vec3> vec_vertices_base;
    std::vector<glm::vec3> vec_changed;
    std::vector<glm::vec4> vec_color;
    std::vector<glm::vec4> vec_color_base;
    std::vector<glm::vec3> vec_indices;
    std::vector<unsigned short> vec_indices_ushort;
    std::vector<QString> vec_annotationText;
    std::vector<glm::vec2> vec_doubled_points;
    std::vector<FaceComponent> vec_faceComponents;




    void upperLipraiser();
    void eyeCloser();

    std::vector<short> reference;
    std::vector<glm::vec3> lipraiser;

};

#endif // FACEMODELCANDIDE_H
