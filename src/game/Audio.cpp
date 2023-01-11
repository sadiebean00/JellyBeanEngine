#include "Audio.h"

/*
*	The Audio class is relatively simple as we have just two things 
*	occuring. The first thing that we have happen is that we make sure
*	that the Audio does not start when the game is first booted.
*	
*	Afterwards, the system then creates a new entity called audio
*	which adds the newest component as a new audio source. 
*/

void Audio::onInit()
{
	audioStart = false;

	std::shared_ptr<AudioSource> audio = getEntity()->addComponent<AudioSource>();
}
