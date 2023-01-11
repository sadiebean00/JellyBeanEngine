#pragma once

#include "Component.h"
#include <AL/al.h>
#include <AL/alc.h>
#include "AudioClip.h"


namespace JellyBean_Engine
{
	/*
	*	This is my Audio Source class, which inherits from our 
	*	component class. Here we set the playback for the clip
	*	previously set in our Audio Clip class. We also set the
	*	volume for the Audio Source.
	*/

	struct AudioSource : Component
	{
		AudioSource();

		void setClip(std::shared_ptr<AudioClip> clip);

	private:
		ALuint sid;

		float volume;
		float variance;
	};

}