#ifndef TIME_H
#define TIME_H

#include <iostream>
#include "glfw3.h"
class Time
{
    public:
        Time();
        virtual ~Time();
        float get_deltatime();
        int get_fps();
        void update();
        struct Timer {
        public:
		      void init() { timer_start_time = 0.0f; timer_current_time = 0.0f; }
          void start() { timer_start_time = glfwGetTime(); }
          void stop() { timer_current_time = 0.0f; }
          float seconds() { timer_current_time = glfwGetTime(); return timer_current_time - timer_start_time; }
        private:
          float timer_start_time;
          float timer_current_time;
        };
        Timer timer;
    private:
      float dt;
      float current_time,
            previous_time,
            last_time = 0;
      int fps;


};

#endif // TIME_H
