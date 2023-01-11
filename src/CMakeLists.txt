cmake_minimum_required(VERSION 3.0)
project(JELLYBEANENGINE)

include_directories(
	src
	contrib
)

if(MSVC)
	include_directories (
		contrib/include
	)
	link_directories(
		contrib/lib
	)
else()
endif()

if(MSVC)
	add_definitions(-DSDL_MAIN_HANDLED)
endif()

add_library(rend
	src/rend/Buffer.cpp
	src/rend/Context.cpp
	src/rend/Exception.cpp
	src/rend/Mesh.cpp
	src/rend/RenderTexture.cpp
	src/rend/Shader.cpp
	src/rend/Texture.cpp
	src/rend/Util.cpp)

add_library(jellybeanengine
	src/jellybeanengine/AudioClip.h
	src/jellybeanengine/AudioClip.cpp
	src/jellybeanengine/AudioSource.h
	src/jellybeanengine/AudioSource.cpp
	src/jellybeanengine/Camera.h
	src/jellybeanengine/Camera.cpp
	src/jellybeanengine/Collision.h
	src/jellybeanengine/Collision.cpp
	src/jellybeanengine/Component.h	
	src/jellybeanengine/Component.cpp
	src/jellybeanengine/Controller.h
	src/jellybeanengine/Controller.cpp
	src/jellybeanengine/Core.h
	src/jellybeanengine/Core.cpp
	src/jellybeanengine/Entity.h
	src/jellybeanengine/Entity.cpp
	src/jellybeanengine/Exception.h
	src/jellybeanengine/Exception.cpp
	src/jellybeanengine/GameEnvironment.h
	src/jellybeanengine/GameEnvironment.cpp
	src/jellybeanengine/GameScreen.h
	src/jellybeanengine/GameScreen.cpp
	src/jellybeanengine/jellybeanengine.h 
	src/mathutils.h 
	src/jellybeanengine/Materials.h
	src/jellybeanengine/Materials.cpp
	src/jellybeanengine/Model.h
	src/jellybeanengine/Model.cpp
	src/jellybeanengine/RendererModel.h
	src/jellybeanengine/RendererModel.cpp
	src/jellybeanengine/Resource.h
	src/jellybeanengine/Resource.cpp
	src/jellybeanengine/Resources.h
	src/jellybeanengine/Resources.cpp
	src/jellybeanengine/ShaderProgram.h
	src/jellybeanengine/ShaderProgram.cpp
	src/jellybeanengine/Texture.h
	src/jellybeanengine/Texture.cpp
	src/jellybeanengine/Transform.h
	src/jellybeanengine/Transform.cpp
	src/jellybeanengine/TriangleRenderer.h
	src/jellybeanengine/TriangleRenderer.cpp
	src/jellybeanengine/Triggers.h
	src/jellybeanengine/Triggers.cpp
	src/jellybeanengine/VertexArray.h
	src/jellybeanengine/VertexArray.cpp
	src/jellybeanengine/VertexBuffer.h
	src/jellybeanengine/VertexBuffer.cpp
)

set_target_properties(jellybeanengine PROPERTIES LINKER_LANGUAGE CXX)

add_executable(game 
	src/game/main.cpp
	src/game/MainPlayer.h
	src/game/MainPlayer.cpp
	src/game/MainEnemy.h
	src/game/MainEnemy.cpp
	src/game/Audio.h
	src/game/Audio.cpp
)

target_link_libraries (game jellybeanengine SDL2 glew32 opengl32 openal32)
