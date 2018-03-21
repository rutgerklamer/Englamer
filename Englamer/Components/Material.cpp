#include "Englamer/Components/Material.h"

Material::Material() : Component()
{
	set_component_type(MATERIAL);
	color = glm::vec3(1,1,1);
	texture_id = 0;
}

Material::~Material()
{

}

void Material::set_color(glm::vec3 c)
{
	color = c;
}

glm::vec3 Material::get_color()
{
	return color;
}

void Material::load_texture(const char* file)
{
	texture_id = Resourcemanager::get_texture(file);
}

uint Material::get_texture()
{
	return texture_id;
}
