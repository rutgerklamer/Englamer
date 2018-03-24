#ifndef SCENE1_H
#define SCENE1_H

#include "Englamer/Scene/Superscene.h"

#include "Demo/Player.h"
#include "Demo/SceneLight.h"

class Scene1 : public Superscene {
	public:
		Scene1();
		~Scene1();
		virtual void update(float dt);
	private:
		SceneLight* sl;
};

#endif SCENE1_H
