#include "AudioSource.h"

namespace JellyBean_Engine
{
	AudioSource::AudioSource()
	{

	}

	/*
	*	This sets the clips that we are going to use for our audio
	*	files by referencing our AudioClip class. We also set the 
	*	audio buffer in here.
	*/

	void AudioSource::setClip(std::shared_ptr<AudioClip> clip)
	{
		sid = 0;
		alGenSources(1, &sid);

		alSourcei(sid, AL_BUFFER, clip->id);
		alSourcePlay(sid);
	}


}