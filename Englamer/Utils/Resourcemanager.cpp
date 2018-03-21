#include "Englamer/Utils/Resourcemanager.h"
#include "Englamer/Utils/Objloader.h"
#include "Englamer/Utils/Textureloader.h"

Resourcemanager Resourcemanager::m_resourcemanager;

std::vector<vertex> Resourcemanager::get_model(const char* file)
{
	if (m_resourcemanager.models.count(file) == 0)
		m_resourcemanager.models[file] = objloader::load_model(file);
	return m_resourcemanager.models[file];
}

uint Resourcemanager::get_texture(const char* file)
{
	if (m_resourcemanager.textures.count(file) == 0)
		m_resourcemanager.textures[file] = textureloader::load_texture(file);
	return m_resourcemanager.textures[file];
}
