#ifndef RESOURCEMANAGER_H
#define RESOURCEMANAGER_H

#include <map>

#include "Englamer/Components/Mesh.h"

class Resourcemanager {
	public:
		static Resourcemanager m_resourcemanager;
		static std::vector<vertex> get_model(const char* file);
		static uint get_texture(const char* file);
	private:
		std::map<const char*, std::vector<vertex>> models;
		std::map<const char*, uint> textures;
};

#endif RESOURCEMANAGER_H
