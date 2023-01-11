#include "bugl.h"
#include "VertexArray.h"
#include "VertexBuffer.h"
#include <exception>

namespace JellyBean_Engine
{
	VertexArray::VertexArray()
	{
		glGenVertexArrays(1, &id);

		if (!id)
		{
			throw std::exception();
		}

		buffers.resize(20);
		dirty = true;
		vertCount = 0;
	}

	VertexArray::VertexArray(std::string path)
	{
		id = buLoadModel(path, &vertCount);
		dirty = false;
	}



	VertexArray::~VertexArray()
	{
		glDeleteVertexArrays(1, &id);
	}

	size_t VertexArray::getVertCount()
	{
		return vertCount;
	}

	void VertexArray::setBuffer(int position, std::shared_ptr<VertexBuffer> buffer)
	{
		buffers.at(position) = buffer;
		dirty = true;
	}

	GLuint VertexArray::getId()
	{
		if (dirty)
		{
			dirty = false;
			glBindVertexArray(id);

			for (size_t i = 0; i < buffers.size(); i++)
			{
				if (!buffers.at(i)) continue;

				glBindBuffer(GL_ARRAY_BUFFER, buffers.at(i)->getId());

				glVertexAttribPointer(i, buffers.at(i)->getComponents(), GL_FLOAT, GL_FALSE,
					0, (void*)0);

				glEnableVertexAttribArray(i);
			}

			glBindVertexArray(0);
		}

		return id;
	}
}