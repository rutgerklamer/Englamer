#include "Englamer/Core/Config.h"

namespace config
{
	int width = 800;
	int height = 600;
	std::string window_name = "Englamer";
	int major = 3;
	int minor = 3;
	glm::vec4 clear_color = glm::vec4(0.2f, 0.0f, 0.0f, 1.0f);
	bool mouse_lock = false;
}

bool config::read_config(char* filepath)
{
	std::ifstream ip(filepath);
	std::string ini_file;
	std::string line;
	while (std::getline(ip, line))
			ini_file += line + "\n";

	std::map<std::string, std::string> settings;
	std::string string_seperation = "=";
	std::string prevstring = "";
	std::string group;
	while (ini_file.size()) {
		int index = ini_file.find("=");
		if (ini_file.find("\n") < index)
			index = ini_file.find("\n");
		if (prevstring.find("[") != std::string::npos)
			group = prevstring;
		if (index != std::string::npos){
			settings[group + "/" + prevstring] = ini_file.substr(0, index);
			prevstring = ini_file.substr(0, index);
			ini_file = ini_file.substr(index + 1);
		}
	}

	config::width = stoi(settings["[display]/width"]);
	config::height = stoi(settings["[display]/height"]);
	config::window_name = settings["[display]/window_name"];
	config::major = stoi(settings["[glfw]/major"]);
	config::minor = stoi(settings["[glfw]/minor"]);
	config::mouse_lock = (settings["[glfw]/mouse_lock"] == "true" ? true : false);
	std::string str = settings["[glfw]/clear_color"];

	std::vector<std::string> result;
	while (str.size()){
		int index = str.find(":");
		if (index != std::string::npos){
			result.push_back(str.substr(0, index));
			prevstring = str.substr(0, index);
			str = str.substr(index + 1);
			if (str.size() == 0)result.push_back(str);
		}
		else {
			result.push_back(str);
			str = "";
		}
	}

	float a[4];
	for (int i = 0; i < result.size(); i++)
		a[i] = stof(result[i]);
	config::clear_color = glm::vec4(a[0], a[1], a[2], a[3]);

	return true;
}
