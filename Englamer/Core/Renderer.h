#ifndef RENDERER_H
#define RENDERER_H

#include <string>

#include "Englamer/Core/Config.h"
#include "Englamer/Scene/Superscene.h"
#include "Englamer/Core/Shader.h"
#include "Englamer/Entities/Entity.h"
#include "Englamer/Maths/Intersect.h"

#include <vector>

class Renderer {
	public:
		Renderer();
		~Renderer();
		void render_scene(Superscene* scene, Shader* shader);
		void render_skybox(Skybox* skybox, Shader* shader, Camera* camera);
		Shader* m_skybox_shader;
#ifdef _DEBUG
		void render_debug_mesh(Entity* entity, Shader* shader, Camera* camera);
		void render_debug_camera(Shader* shader, Camera* camera, Camera* render_camera);
		std::vector<glm::vec4> render_debug_calculate_frustum_planes(Camera* camera);
		void render_debug_set_boundaries(glm::vec3 min, glm::vec3 max);
		Mesh* m_debug_mesh;
		Shader* m_debug_shader;
#endif _DEBUG
};
#endif RENDERER_H
