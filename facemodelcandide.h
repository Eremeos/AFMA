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
    std::vector<glm::vec4> vec_color;
    std::vector<glm::vec3> vec_indices;


};

#endif // FACEMODELCANDIDE_H
