#version 400 core

in vec4 fragmentColor ;
out vec4 color ;
in vec2 UV;
uniform sampler2D myTextureSampler;
out vec3 c;

void main(){

 //color = fragmentColor;

 gl_FragColor = texture2D(myTextureSampler, UV);
}
