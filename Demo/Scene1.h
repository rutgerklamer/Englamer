#ifndef SCENE1_H
#define SCENE1_H

#include "Englamer/Scene/Superscene.h"

#include "Demo/Player.h"

class Scene1 : public Superscene {
	public:
		Scene1();
		~Scene1();
		virtual void update(float dt);
	private:
};

#endif SCENE1_H