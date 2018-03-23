#version 410 core

layout (location = 0) in vec3 Vertices;
layout (location = 1) in vec2 TexCoords;
layout (location = 2) in vec3 Normals;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;
out vec2 tex_coords;
out vec3 normal;
out vec3 fragment_position;

void main(void)
{
  fragment_position = vec4(model * vec4(Vertices,1)).xyz;
  normal = mat3(transpose(inverse(model))) * Normals;
  tex_coords = TexCoords;
  gl_Position = projection * view * model * vec4(Vertices,1);
}
