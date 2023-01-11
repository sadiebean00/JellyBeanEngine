#pragma once
#include <AL/al.h>
#include <AL/alc.h>
#include <vector>
#include <string>
#include "Resource.h"

namespace JellyBean_Engine
{
	struct AudioSource;
	
	/*
	*	This is my Audio Clip header file, which references the Audio
	*	Source class. Here we set the functions for our initialise
	*	and loadOgg classes. We also set the format that we're going
	*	to use as well as the buffer data for the class.
	*/

	struct AudioClip : Resource
	{ 
		void onInit();

		void loadOgg(const std::string& fileName, std::vector<char>& buffer, ALenum& format, ALsizei& freq);

	private:

		friend struct AudioSource;
		ALenum format;
		ALsizei freq;
		ALuint id;
		std::vector<char> bufferData;

	};


}