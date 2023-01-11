#include "VertexBuffer.h"

#include <exception>

namespace JellyBean_Engine
{
	VertexBuffer::VertexBuffer()
	{
		glGenBuffers(1, &id);

		if (!id)
		{
			throw std::exception();
		}

		dirty = true;
		components = 0;
	}

	VertexBuffer::~VertexBuffer()
	{
		glDeleteBuffers(1, &id);
	}

	void VertexBuffer::add(glm::vec3 value)
	{
		data.push_back(value.x);
		data.push_back(value.y);
		data.push_back(value.z);
		components = 3;

		dirty = true;
	}

	void VertexBuffer::add(glm::vec4 value)
	{
		data.push_back(value.x);
		data.push_back(value.y);
		data.push_back(value.z);
		data.push_back(value.w);
		components = 4;

		dirty = true;
	}

	GLuint VertexBuffer::getId()
	{
		if (dirty)
		{
			glBindBuffer(GL_ARRAY_BUFFER, id);

			glBufferData(GL_ARRAY_BUFFER, data.size() * sizeof(data.at(0)), &data.at(0),
				GL_STATIC_DRAW);

			glBindBuffer(GL_ARRAY_BUFFER, 0);

			dirty = false;
		}
		return id;
	}

	int VertexBuffer::getComponents()
	{
		return components;
	}
}