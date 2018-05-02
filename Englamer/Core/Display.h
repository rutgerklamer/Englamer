#ifndef DISPLAY_H
#define DISPLAY_H

#include <iostream>

#include "Englamer/Core/Config.h"
#include "Englamer/Core/Input.h"

class Display
{
	public:
		static GLFWwindow* m_window;
      /**
           * Constructor
           */
        Display();
        /**
            * Destructor
            */
        virtual ~Display();
		/**
			* Create a glfw window
			*/
		void create_context();
		/**
			* Update the window contents
			*/
		void update();
		/**
			* Swap buffers and update poll events
			*/
		void late_update();
};

#endif DISPLAY_H
