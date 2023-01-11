#pragma once

#include "SDL.h"

namespace JellyBean_Engine
{
	
	/*
	*	This stores the width and height functions of the game screen
	*	which is then accessed through the core. For the purposes of 
	*	the demo, I have set the scales to be 1000 x 800.
	*/

	struct GameScreen
	{
	public:

		int getWidth();

		int getHeight();

	private:
		int height = 800;
		int width = 1000;

	};

}