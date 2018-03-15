#ifndef RESOURCEMANAGER_H
#define RESOURCEMANAGER_H

#include <map>

#include "Englamer/Entities/Mesh.h"

class Resourcemanager {
	public:
		static Resourcemanager m_resourcemanager;
		static std::vector<vertex> get_model(const char* file);
	private:
		std::map<const char*, std::vector<vertex>> models;
};

#endif RESOURCEMANAGER_H