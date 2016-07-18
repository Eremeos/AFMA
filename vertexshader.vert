#version 400 core

out vec4 fragmentColor  ;





layout(location = 0) in vec3 vertexPosition_modelspace ;
layout(location = 1) in vec4 colorBuffer ;

void main(void)
{
    gl_Position = vec4(vertexPosition_modelspace,1);

    fragmentColor = vec4(colorBuffer);


}
