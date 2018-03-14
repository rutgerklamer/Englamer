#include "Englamer/Scene/Scenemanager.h"

Scenemanager::Scenemanager()
{
	this->m_scene_pointer = -1;
}

Scenemanager::~Scenemanager()
{

}

Superscene* Scenemanager::get_scene()
{
	return this->m_scenes[m_scene_pointer];
}

void Scenemanager::add_scene(Superscene* scene)
{
	this->m_scenes.push_back(scene);
	this->m_scene_pointer++;
}
