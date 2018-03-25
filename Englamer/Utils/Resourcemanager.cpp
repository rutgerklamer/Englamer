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

uint Resourcemanager::load_cubemap(std::vector<const char*> faces)
{
	uint textureID;

	int textureWidth, textureHeight;

	glGenTextures(1, &textureID);
	glBindTexture(GL_TEXTURE_CUBE_MAP, textureID);

	for (GLuint i = 0; i < faces.size(); i++) {
		unsigned char* image = SOIL_load_image(faces[i], &textureWidth, &textureHeight, 0, SOIL_LOAD_RGB);

		glTexImage2D(GL_TEXTURE_CUBE_MAP_POSITIVE_X + i, 0, GL_RGB, textureWidth, textureHeight, 0, GL_RGB, GL_UNSIGNED_BYTE, image);
		SOIL_free_image_data(image);
	}

	glTexParameteri( GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MAG_FILTER, GL_LINEAR );
	glTexParameteri( GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MIN_FILTER, GL_LINEAR );
	glTexParameteri( GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE );
	glTexParameteri( GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE );
	glTexParameteri( GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_R, GL_CLAMP_TO_EDGE );
	glBindTexture(GL_TEXTURE_CUBE_MAP, 0);

	return textureID;
}
