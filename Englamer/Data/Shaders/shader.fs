#version 410 core

out vec4 final_color;

in vec2 tex_coords;

uniform vec3 color;
uniform sampler2D texture;

void main() {
  vec3 diffuse_texture;
  if (color.r + color.g + color.b == 0)
   {
     diffuse_texture = texture2D(texture, vec2(tex_coords.x, 1.0 - tex_coords.y)).xyz;
   } else {
     diffuse_texture = vec3(color.r, color.g, color.b);
   }
  final_color = vec4(diffuse_texture,1);
}
