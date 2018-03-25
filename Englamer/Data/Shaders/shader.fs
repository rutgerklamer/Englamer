#version 410 core

out vec4 final_color;

in vec2 tex_coords;
in vec3 normal;
in vec3 fragment_position;

struct Light {
    vec3 position;
    vec3 color;
    float specular_strength;
    float intensity;
    float is_light;
};
#define light_amount 10
uniform Light lights[light_amount];

struct Material {
    vec3 ambient;
    vec3 diffuse;
    vec3 specular;
    float shininess;
};

uniform Material material;

uniform vec3 color;
uniform vec3 camera_position;
uniform sampler2D texture;

vec3 getLight(Light light_data)
{
    vec3 E = normalize(camera_position );
    vec3 L = normalize(light_data.position - fragment_position);
    vec3 H = normalize(E + L);
    vec3 N = normalize(normal);
    vec3 ambient = light_data.color * 0.1f;
    vec3 diffuse = light_data.color * max(dot(N, L), 0);

    vec3 reflectDir = reflect(L, normal);
    vec3 specularTerm = light_data.color * pow(max(dot(E, reflectDir), 0), material.shininess*128.0f) * material.specular;

    float distanceToLight = length(L);
    return (ambient + ((diffuse + specularTerm) * light_data.intensity )* distanceToLight);
}

void main() {
  vec3 diffuse_texture;
  if (color.r + color.g + color.b == 0)
   {
     diffuse_texture = texture2D(texture, vec2(tex_coords.x, 1.0 - tex_coords.y)).xyz;
   } else {
     diffuse_texture = vec3(color.r, color.g, color.b);
   }

   vec3 result = vec3(0,0,0);
   for (int i = 0; i < light_amount; i++){
    if (lights[i].is_light > 0.0f) {
      result += getLight(lights[i]);
    } else if (i == 0) {
      result = vec3(1,1,1);
    }
   }
   final_color = vec4(diffuse_texture * result,1);
}
