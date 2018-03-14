#ifndef SCENEMANAGER_H
#define SCENEMANAGER_H

#include <vector>
#include "Englamer/Scene/Superscene.h"

class Scenemanager {
	public:
		Scenemanager();
		~Scenemanager();
		void add_scene(Superscene* scene);
		Superscene* get_scene();
	private:
		std::vector<Superscene*> m_scenes;
		int						 m_scene_pointer;
};

#endif SCENEMANAGER_H