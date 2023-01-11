#pragma once

#include "glew.h"
#include "SDL.h"
#include <GLM/glm.hpp>
#include <GLM/gtc/matrix_transform.hpp>
#include <GLM/gtc/type_ptr.hpp>
#include <GLM/gtx/transform.hpp> 
#include <exception>
#include <iostream>
#include <memory>
#include "Component.h"
#include "VertexArray.h"
#include "VertexBuffer.h"
#include "ShaderProgram.h"

namespace JellyBean_Engine
{
	struct VertexArray;
	struct ShaderProgram;
	struct Transform;

	/*
	*	This is the basic class for a triangle renderer. We can use this
	*	as a basis for the model renderer as they use triangles to
	*	render properly.
	*/
	
	struct TriangleRenderer : Component
	{
		TriangleRenderer();
		void onTick();
		void onDisplay();
		void onBegin();

	private:
		std::shared_ptr<ShaderProgram> shader;
		std::shared_ptr<VertexArray> vao;
		std::shared_ptr<VertexArray> cat;
	};






}