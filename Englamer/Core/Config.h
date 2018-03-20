#ifndef CONFIG_H
#define CONFIG_H

#include <GL/glew.h>
#include <glfw3.h>
#include <glm/glm.hpp>
#include <vector>
#include <map>
#include <fstream>
#include <string>
#include <algorithm>

namespace config {
	extern int width;
	extern int height;
	extern std::string window_name;
	extern int major;
	extern int minor;
	extern glm::vec4 clear_color;
	extern bool mouse_lock;

	/**
		* Load a simple ini file
		* Using a simple program
		*/
	bool read_config(char* filepath);
}

#endif CONFIG_H
