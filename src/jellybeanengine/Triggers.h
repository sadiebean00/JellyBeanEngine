#include "Component.h"

namespace JellyBean_Engine
{
	struct Core;

	/*
	*	This is my Trigger class where the code relies on the
	*	component to see if the game has caused any triggers, for
	*	example collisions with anything else.
	*/

	struct Triggers : Component
	{
		void onTick();

	private:
		friend struct JellyBean_Engine::Core;
	};

}