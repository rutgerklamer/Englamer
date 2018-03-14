#include "Englamer/Utils/Resourcemanager.h"

Resourcemanager Resourcemanager::m_resourcemanager;

bool Resourcemanager::does_object_exist(const char* file)
{
	if (m_resourcemanager.models.count(file) != 0)
		return true;
	return false;
}

void Resourcemanager::create_object_existance(const char* file, std::vector<vertex>* model_data)
{
	m_resourcemanager.models[file] = *(model_data);
}

std::vector<vertex> Resourcemanager::get_object_existance(const char*file)
{
	if (m_resourcemanager.models.count(file) != 0)
		return m_resourcemanager.models[file];
	else {
		std::vector<vertex> l;
		return l;
	}
}