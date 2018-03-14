#ifndef RESOURCEMANAGER_H
#define RESOURCEMANAGER_H

#include <map>

#include <Englamer/Entities/Mesh.h>

class Resourcemanager {
	public:
		static Resourcemanager m_resourcemanager;
		static bool does_object_exist(const char* file);
		static std::vector<vertex> get_object_existance(const char* file);
		static void create_object_existance(const char* file, std::vector<vertex>* model_data);
	private:
		std::map <const char*, std::vector<vertex>> models;
};

#endif RESOURCEMANAGER_H