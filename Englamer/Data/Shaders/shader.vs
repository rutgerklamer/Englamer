#version 410 core

layout (location = 0) in vec3 Vertices;
layout (location = 1) in vec2 TexCoords;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;
out vec2 tex_coords;

void main(void)
{
  tex_coords = TexCoords;
  gl_Position = projection * view * model * vec4(Vertices,1);
}