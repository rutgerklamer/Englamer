#version 410 core

out vec4 final_color;

uniform vec3 color;

void main() {
   final_color = vec4(color,1);
}
