#ifndef SCENELIGHT_H
#define SCENELIGHT_H

#include <iostream>

#include "Englamer/Entities/Entity.h"

class SceneLight : public Entity {
	public:
		SceneLight();
		~SceneLight();
		virtual void update(float dt);
		virtual void collision(Entity* other_entity);
	private:
};

#endif SCENELIGHT_H
