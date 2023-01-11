#pragma once

#include <vector>
#include <SDL.h>

namespace JellyBean_Engine
{
	struct Core;
	
	/*
	*	This is my Controller class that utilises the SDLK function 
	*	in order to get our keycodes needed. We also use the core class
	*	in order for our player to see what we're doing keycode wise.
	* 
	*	In order to avoid our player constantly moving in one direction
	*	we also added a removeKey function, so that the key's aren't
	*	getting stuck.
	*/

	struct Controller
	{
		bool getKey(int keyCode);

		bool getKeyDown(int keyCode);

		bool getKeyUp(int keyCode);

	private:
		friend struct JellyBean_Engine::Core;
		std::vector<int> keyCodes;
		void removeKey(int keyCode);
	};

}