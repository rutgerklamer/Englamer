#include "Englamer/Components/Material.h"

Material::Material() : Component()
{
	set_component_type(MATERIAL);
	m_material.color = glm::vec3(1,1,1);
	m_material.texture_id = 0;
	m_material.ambient = glm::vec3(0.02,0.02,0.02);
	m_material.diffuse = glm::vec3(0.01, 0.01, 0.01);
	m_material.specular = glm::vec3(0.4, 0.4, 0.4);
	m_material.shininess = 0.078125f;
}

Material::~Material()
{

}

void Material::set_color(glm::vec3 c)
{
	m_material.color = c;
}

glm::vec3 Material::get_color()
{
	return m_material.color;
}

void Material::load_texture(const char* file)
{
	m_material.texture_id = Resourcemanager::get_texture(file);
}

uint Material::get_texture()
{
	return m_material.texture_id;
}

glm::vec3 Material::get_ambient()
{
	return m_material.ambient;
}

glm::vec3 Material::get_diffuse()
{
	return m_material.diffuse;
}

glm::vec3 Material::get_specular()
{
	return m_material.specular;
}

float Material::get_shininess()
{
	return m_material.shininess;
}

void Material::get_ambient(glm::vec3 a)
{
	m_material.ambient = a;
}

void Material::get_diffuse(glm::vec3 d)
{
	m_material.diffuse = d;
}

void Material::get_specular(glm::vec3 s)
{
	m_material.specular = s;
}

void Material::get_shininess(float s)
{
	m_material.shininess = s;
}


uint Material::get_cubemap()
{
  return m_material.cubemap_id;
}

void Material::load_cubemap(std::string right, std::string left, std::string up, std::string down, std::string back, std::string front)
{
  std::vector<const char*> faces2;
    faces2.push_back(right.c_str());
    faces2.push_back(left.c_str());
    faces2.push_back(up.c_str());
    faces2.push_back(down.c_str());
    faces2.push_back(back.c_str());
    faces2.push_back(front.c_str());

   m_material.cubemap_id = Resourcemanager::load_cubemap(faces2);
}
