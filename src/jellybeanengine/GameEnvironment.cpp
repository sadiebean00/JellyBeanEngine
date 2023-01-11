#include "GameEnvironment.h"

namespace JellyBean_Engine
{
	float GameEnvironment::getDeltaTime()
	{
		return deltaTime;
	}

	float GameEnvironment::calculateDeltaTme()
	{
		time = SDL_GetTicks();
		diff = time - lastTime;
		deltaTime = diff / 1000.f;
		lastTime = time;
		return deltaTime;
	}

	GameEnvironment::GameEnvironment()
	{
		lastTime = SDL_GetTicks();
		deltaTime = 0.0f;
	}


}