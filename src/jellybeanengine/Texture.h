#include "Resource.h"
#include "ShaderProgram.h"
#pragma once

namespace JellyBean_Engine
{
	struct RendererModel;

	/*
	*	This is our Texture class that we use to store the texture 
	*	images. In order to properly use these textures, I had to
	*	include stb_image which allows SDL to acknowledge and read 
	*	image files.
	*/

	struct Texture : Resource
	{
		void onInit();
		void loadTexture();
		
		GLuint getId();

		glm::vec2 getSize();

	private:
		friend struct JellyBean_Engine::RendererModel;
		glm::vec2 size;
		int w = 0;
		int h = 0;
		int channels = 0;
		GLuint id;
	};



}