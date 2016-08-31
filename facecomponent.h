#ifndef FACECOMPONENT_H
#define FACECOMPONENT_H

#include <glm/glm.hpp>
#include <vector>

class FaceComponent
{
public:
    FaceComponent();


    std::vector<short> vec_reference_point;
    std::vector<glm::vec3> vec_vertices;

};

#endif // FACECOMPONENT_H
