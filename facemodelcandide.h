#ifndef FACEMODELCANDIDE_H
#define FACEMODELCANDIDE_H

#include <glm/glm.hpp>
#include <vector>

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

    struct lefteye{
        std::vector<short> referencePoint;
        std::vector<glm::vec3> vertice;
    };

    void upperLipraiser();

};

#endif // FACEMODELCANDIDE_H
