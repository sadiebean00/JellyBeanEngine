#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"
#include "Texture.h"
#include "Exception.h"

namespace JellyBean_Engine
{
	void Texture::onInit()
	{
		unsigned char* texture = stbi_load(getPath().c_str(), &w, &h, &channels, 4);
		if (!texture)
		{
			throw Exception("Failed to open file '" + getPath() + "' texture");
		}

		id = 0;
		glGenTextures(1, &id);
		if (!id)
		{
			throw Exception("No texture ID");
		}

		glBindTexture(GL_TEXTURE_2D, id);

		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, w, h, 0, GL_RGBA, GL_UNSIGNED_BYTE, texture);

		free(texture);

		glGenerateMipmap(GL_TEXTURE_2D);
	}

	GLuint Texture::getId()
	{
		return id;
	}

	glm::vec2 Texture::getSize()
	{
		return size;
	}
}