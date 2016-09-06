#ifndef FACECOMPONENT_H
#define FACECOMPONENT_H

#include <glm/glm.hpp>
#include <vector>
#include <QString>

class FaceComponent
{
public:
    FaceComponent();
    FaceComponent(QString name);

    QString name;
    std::vector<short> vec_reference_point;
    std::vector<glm::vec3> vec_vertices;
    std::vector<glm::vec3> vec_moved;
    std::vector<QString> vec_name;

};

#endif // FACECOMPONENT_H
