#version 400 core
out vec3 fragmentcolor  ;

layout(location = 0) in vec3 vertexPosition_modelspace ;


void main(void)
{
    gl_Position = vec4(vertexPosition_modelspace,1);

    fragmentcolor = vec3(1,0,0);

}
