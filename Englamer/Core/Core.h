#ifndef CORE_H
#define CORE_H

#include <iostream>

#include "Englamer/Core/Config.h"
#include "Englamer/Core/Display.h"
#include "Englamer/Core/Camera.h"
#include "Englamer/Scene/Scenemanager.h"
#include "Englamer/Core/Input.h"
#include "Englamer/Core/Shader.h"
#include "Englamer/Core/Renderer.h"
#include "Englamer/Utils/Time.h"

class Core {
	public:
		/**
			* Constructor
			*/
		Core();
		/**
			* Destructor
			*/
		virtual ~Core();
		/**
			* Setup a late initializer
			*/
		void init();
		/**
			* Loop till the display needs to be destroyed
			*/
		void run();
		/**
				* add a scene to the scenemanager
		*/
		void add_scene(Superscene* scene);
	private:
		Display*	 m_display;
		Camera*		 m_camera;
		Scenemanager m_scenemanager;
		Shader* shader;
		Renderer* renderer;
		Time time;
};
#endif CORE_H
