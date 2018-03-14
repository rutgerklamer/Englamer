#ifndef PLAYER_H
#define PLAYER_H

#include "Englamer/Entities/Entity.h"

class Player : public Entity {
	public:
		Player();
		~Player();
		virtual void update(float dt);
	private:
};

#endif PLAYER_H