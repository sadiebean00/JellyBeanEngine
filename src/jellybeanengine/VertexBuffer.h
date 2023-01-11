#pragma once

#include "glew.h"
#include <GLM/glm.hpp>
#include <vector>
#include <memory>

namespace JellyBean_Engine
{
	/*
	*	The VBO or Vertex Buffer class is the class that stores the		
	*	buffers for the model program. Once we have stored these pieces 
	*	of information, we send it back to the VAO class.
	*/

	struct VertexBuffer
	{
	public:

		VertexBuffer();

		~VertexBuffer();

		void add(glm::vec3 value);

		void add(glm::vec4 value);

		GLuint getId();

		int getComponents();

	private:
		GLuint id;
		std::vector<GLfloat> data;
		bool dirty;
		int components;

	};




}