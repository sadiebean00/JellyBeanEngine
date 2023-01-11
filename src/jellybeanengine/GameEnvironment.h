#pragma once

#include <SDL.h>
namespace JellyBean_Engine
{
	
	/*
	*	This is the game environment class where we store all of our
	*	time units that is needed when calculating how fast we need
	*	something to move.
	*/

	struct GameEnvironment
	{
		float getDeltaTime();

		float calculateDeltaTme();

		GameEnvironment();

	private:
		float time;
		float diff;
		float deltaTime;
		float lastTime;
	};

}