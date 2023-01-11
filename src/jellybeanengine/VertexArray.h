#pragma once

#include "glew.h"
#include <vector>
#include <memory>
#include <string>

namespace JellyBean_Engine
{
	struct VertexBuffer;

	/*
	*	The vertex array class, or vao class, stores all of the vertex
	*	array data for the model that we give it. We also utilise the
	*	getVertCount to help us see how big the model is in vertices.
	* 
	*	We also utilise the file bugl.h that is provided in order to
	*	properly load these models.
	*/

	struct VertexArray
	{
	public:

		VertexArray();

		VertexArray(std::string path); 

		~VertexArray();

		void setBuffer(int position, std::shared_ptr<VertexBuffer> buffers);

		GLuint getId();

		size_t getVertCount();

	private:
		GLuint id;
		std::vector<std::shared_ptr<VertexBuffer>> buffers;
		bool dirty;
		size_t vertCount;
	};




}