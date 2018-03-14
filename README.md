Englamer
====

Englamer is a game making framework which uses openGL as a rendering system

Building
-----

On Debian-based Linux, install the following libraries:

	sudo apt-get install -y git cmake doxygen g++ libgl1-mesa-dev libglu1-mesa-dev libxrandr-dev libxi-dev

On Windows and MacOS:
	Install make and cmake, and make sure you have atleast the C++11 compiler installed.
Use those command to build:

- mkdir build
- cd build
- cmake ..
- make

  Run
  -----
Then you can run the demo:

	./demo


  Documentation
  -----
   Make sure doxygen is installed
   the use these commands

      doxygen Doxyfile

Libraries
---------

- glfw: <http://www.glfw.org/>
- glew: <http://glew.sourceforge.net/>
- glm: <http://glm.g-truc.net/>
- chaiscript: <http://chaiscript.com/>

References
-----

- <http://learnopengl.com/>

License
-------

Copyright 2018 Rutger Klamer <rutger.klamer@gmail.com>

This project is provided as opensource. Do with it whatever you want.
