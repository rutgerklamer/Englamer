#ifndef SUPERSCENE_H
#define SUPERSCENE_H

#include <vector>

#include "Englamer/Entities/Entity.h"
#include "Englamer/Core/Camera.h"
#include "Englamer/Core/Input.h"
#include "Englamer/Maths/Intersect.h"
#include "Englamer/Scene/Skybox.h"

class Superscene {
	public:
		Superscene();
		virtual ~Superscene();
		void cleanup();
		void add_child(Entity* entity);
		void add_skybox(std::string right, std::string left, std::string up, std::string down, std::string back, std::string front);
		Skybox* get_skybox();
		void remove_skybox();
		void remove_child(Entity* entity);
		Camera* get_camera();
		virtual void update(float dt);
		void update_children(float dt);
		Shader* get_shader();
		void load_shader(const char* vp, const char* fp);
#ifdef _DEBUG
		void debug_update(float dt);
		Camera* get_debug_camera();
#endif _DEBUG
		// TODO make private
		std::vector<Entity*> m_children;
		std::vector<Entity*> m_lights;
	private:
		Skybox* m_skybox;
		Shader* shader;
		Camera*				 m_camera;
#ifdef _DEBUG
		Camera*				 m_debug_camera;
#endif _DEBUG
};

#endif SUPERSCENE_H
