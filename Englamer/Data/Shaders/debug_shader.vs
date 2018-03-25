#version 410 core

layout (location = 0) in vec3 Vertices;
layout (location = 1) in vec2 TexCoords;
layout (location = 2) in vec3 Normals;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

void main(void)
{
  gl_Position = projection * view * model * vec4(Vertices,1);
}
