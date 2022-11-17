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
	src/rend/Animation.cpp
	src/rend/Buffer.cpp
	src/rend/Mesh.cpp
	src/rend/ModelRenderer.cpp
	src/rend/RenderTexture.cpp
	src/rend/Renderer.cpp
	src/rend/Shader.cpp
	src/rend/Texture.cpp
	src/rend/rend.h
)

add_library(jellybeanengine
	src/jellybeanengine/Core.h
	src/jellybeanengine/jellybeanengine.h 
	src/mathutils.h 
	src/jellybeanengine/Entity.h
	src/jellybeanengine/Component.h
	src/jellybeanengine/TriangleRenderer.h
	src/jellybeanengine/Core.cpp 
	src/jellybeanengine/Entity.cpp
	src/jellybeanengine/Component.cpp
	src/jellybeanengine/TriangleRenderer.cpp
	src/jellybeanengine/Transform.h
	src/jellybeanengine/Transform.cpp
)

set_target_properties(jellybeanengine PROPERTIES LINKER_LANGUAGE CXX)

add_executable(game 
	src/game/main.cpp
)

target_link_libraries (game jellybeanengine rend SDL2 SDL2main glew32 opengl32 openal32)
