# CMake entry point
cmake_minimum_required (VERSION 2.6)
project (englamer)

# delete CMakeCache.txt from the build directory when you edit these options
####################################################################
OPTION(MAKE_DEMO "Create DEMO" ON)
####################################################################

if( CMAKE_BINARY_DIR STREQUAL CMAKE_SOURCE_DIR )
    message( FATAL_ERROR "Please select another Build Directory ! (and give it a clever name, like 'build')" )
endif()
if( CMAKE_SOURCE_DIR MATCHES " " )
	message( "Your Source Directory contains spaces. If you experience problems when compiling, this can be the cause." )
endif()
if( CMAKE_BINARY_DIR MATCHES " " )
	message( "Your Build Directory contains spaces. If you experience problems when compiling, this can be the cause." )
endif()

if(UNIX)
	#set(CMAKE_CXX_FLAGS "-Wall -std=c++0x -pedantic -O2 -g -pg")
	#set(CMAKE_CXX_FLAGS "-Wall -Wstrict-aliasing -std=c++0x -O2")

	set(CMAKE_CXX_FLAGS "-Wall -std=c++11")
  set(CMAKE_C_COMPILER /usr/bin/clang CACHE PATH "" FORCE)
set(CMAKE_CXX_COMPILER /usr/bin/clang++ CACHE PATH "" FORCE)


	# valgrind --leak-check=full ./demo
	# ./demo # creates cmon.out
	# gprof demo gmon.out > analysis.txt
	#set(CMAKE_CXX_FLAGS "-Wall -pg -std=c++11")
endif(UNIX)


if(WIN32)
	# On Visual 2005 and above, this module can set the debug working directory
	list(APPEND CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/external/rpavlik-cmake-modules-1c73e35")
	include(CreateLaunchers)
	include(MSVCMultipleProcessCompile) # /MP

	if(MINGW)
		set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
	ELSE(MINGW)
		add_definitions( "/W3 /D_CRT_SECURE_NO_WARNINGS /wd4514 /nologo" ) # suppress pedantic warnings
	endif(MINGW)
endif(WIN32)


# Compile external dependencies
find_package(OpenGL REQUIRED)

add_subdirectory (external)

include_directories(
	${CMAKE_SOURCE_DIR}/external/glfw-3.0.3/include/GLFW
	${CMAKE_SOURCE_DIR}/external/glew-1.9.0/include
	${CMAKE_SOURCE_DIR}/external/glm-0.9.8.4
	${CMAKE_SOURCE_DIR}/.
)

link_directories(
	${CMAKE_SOURCE_DIR}/external/glfw-3.0.3/src
	${CMAKE_SOURCE_DIR}/external/glew-1.9.0
)

set(ALL_GRAPHICS_LIBS
	${OPENGL_LIBRARY}
	GLFW_303
	GLEW_190
)

add_definitions(
	-DTW_STATIC
	-DTW_NO_LIB_PRAGMA
	-DTW_NO_DIRECT3D
	-DGLEW_STATIC
	-D_CRT_SECURE_NO_WARNINGS
)

set(ENGLAMER_SOURCE
    Englamer/Core/Display.cpp
    Englamer/Core/Core.cpp
	  Englamer/Core/Config.cpp
	  Englamer/Core/Input.cpp
	  Englamer/Core/Renderer.cpp
	  Englamer/Core/Shader.cpp
	  Englamer/Core/Camera.cpp
	  Englamer/Scene/Scenemanager.cpp
	  Englamer/Scene/Superscene.cpp
	  Englamer/Entities/Entity.cpp
	  Englamer/Components/Mesh.cpp
	  Englamer/Components/Component.cpp
	  Englamer/Components/Transform.cpp
	  Englamer/Components/Collider.cpp
	  Englamer/Components/Light.cpp
    Englamer/Components/Material.cpp
	  Englamer/Utils/Resourcemanager.cpp
	  Englamer/Utils/Frustum.cpp
	  Englamer/Maths/Intersect.cpp
	)

####################################################################
# Rugine DEMO                                                        #
####################################################################
IF(MAKE_DEMO)
  set(SOURCES
    Demo/main.cpp
	  Demo/Scene1.cpp
	  Demo/Player.cpp
  )
  add_definitions(-D_DEBUG)
  add_executable(demo ${SOURCES} ${ENGLAMER_SOURCE})

 file(
  	COPY ${CMAKE_SOURCE_DIR}/Englamer/Data
  	DESTINATION ${CMAKE_BINARY_DIR}
  )
  file(
  	COPY ${CMAKE_SOURCE_DIR}/Demo/Assets
  	DESTINATION ${CMAKE_BINARY_DIR}
  )
  target_link_libraries(demo ${ALL_GRAPHICS_LIBS})

ENDIF()
