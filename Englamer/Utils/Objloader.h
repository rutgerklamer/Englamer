#ifndef OBJLOADER_H
#define OBJLOADER_H

#include <vector>

#include "Englamer/Components/Mesh.h"

namespace objloader {
	std::vector<vertex> load_model(const char* path)
	{
		std::vector<vertex> model;
		std::vector<glm::vec3> temp_vertices;
		std::vector<glm::vec2> temp_textures;
		std::vector<glm::vec3> temp_normals;

		std::vector<int> vertexIndices;
		std::vector<int> uvIndices;
		std::vector<int> normalIndices;

		FILE* file = fopen(path, "r");
		if (file == NULL){
			std::cout << "failed to open: " << path << std::endl;
			fclose(file);
		}

		while (1){
			char lineHeader[256];
			int res = fscanf(file, "%s", lineHeader);
			if (res == EOF) 
				break;
			if (strcmp(lineHeader, "v") == 0){
				glm::vec3 vertex;
				fscanf(file, "%f %f %f\n", &vertex.x, &vertex.y, &vertex.z);
				temp_vertices.push_back(vertex);
			}
			else if (strcmp(lineHeader, "vt") == 0) {
				glm::vec2 uv;
				fscanf(file, "%f %f\n", &uv.x, &uv.y);
				temp_textures.push_back(uv);
			}
			else if (strcmp(lineHeader, "vn") == 0) {
				glm::vec3 normal;
				fscanf(file, "%f %f %f\n", &normal.x, &normal.y, &normal.z);
				temp_normals.push_back(normal);
			}
			else if (strcmp(lineHeader, "f") == 0) {

				std::string vertex1, vertex2, vertex3;
				unsigned int vertexIndex[3], uvIndex[3], normalIndex[3];
				int matches = fscanf(file, "%d/%d/%d %d/%d/%d %d/%d/%d\n", &vertexIndex[0], &uvIndex[0], &normalIndex[0], &vertexIndex[1], &uvIndex[1], &normalIndex[1], &vertexIndex[2], &uvIndex[2], &normalIndex[2]);
				if (matches != 9){
					printf("File can't be read\n");
				}
				vertexIndices.push_back(vertexIndex[0]);
				vertexIndices.push_back(vertexIndex[1]);
				vertexIndices.push_back(vertexIndex[2]);
				uvIndices.push_back(uvIndex[0]);
				uvIndices.push_back(uvIndex[1]);
				uvIndices.push_back(uvIndex[2]);
				normalIndices.push_back(normalIndex[0]);
				normalIndices.push_back(normalIndex[1]);
				normalIndices.push_back(normalIndex[2]);
			}
		}
		fclose(file);
		for (unsigned int i = 0; i<vertexIndices.size(); i++) {
			vertex v;
			unsigned int vertexIndex = vertexIndices[i];
			v.x = temp_vertices[vertexIndex - 1].x;
			v.y = temp_vertices[vertexIndex - 1].y;
			v.z = temp_vertices[vertexIndex - 1].z;
			unsigned int uvIndex = uvIndices[i];
			v.uvx = temp_textures[uvIndex - 1].x;
			v.uvy = temp_textures[uvIndex - 1].y;
			unsigned int normalIndex = normalIndices[i];
			v.nx = temp_normals[normalIndex - 1].x;
			v.ny = temp_normals[normalIndex - 1].y;
			v.nz = temp_normals[normalIndex - 1].z;

			model.push_back(v);
		}
		return model;
	}
};

#endif OBJLOADER_H