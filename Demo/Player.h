#ifndef PLAYER_H
#define PLAYER_H

#include "Englamer/Entities/Entity.h"

class Player : public Entity {
	public:
		Player();
		~Player();
		virtual void update(float dt);
		virtual void collision(Entity* other_entity);
	private:
};

#endif PLAYER_H