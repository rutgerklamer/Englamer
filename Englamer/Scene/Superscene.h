#ifndef SUPERSCENE_H
#define SUPERSCENE_H

#include <vector>

#include "Englamer/Entities/Entity.h"
#include "Englamer/Core/Camera.h"
#include "Englamer/Core/Input.h"

class Superscene {
	public:
		Superscene();
		virtual ~Superscene();
		void cleanup();
		void add_child(Entity* entity);
		Camera* get_camera();
		virtual void update(float dt);
		void update_children(float dt);
#ifdef _DEBUG
		void debug_update(float dt);
		Camera* get_debug_camera();
#endif _DEBUG
		// TODO make private
		std::vector<Entity*> m_children;
	private:
		Camera*				 m_camera;
#ifdef _DEBUG
		Camera*				 m_debug_camera;
#endif _DEBUG
};

#endif SUPERSCENE_H