#include "include/SDL.h"
#include "AL/al.h"
#include "AL/alc.h"

#include <memory>
#include <vector>

/*
*	Here we have our Core class which relies on the Entity class for some
*	variables. Here we also initialise the screen that will be seen as well
*	as the start and stop functions. We can also add entities in this
*	class. We've also got a function that checks whether the screen is
*	running.
*/
namespace JellyBean_Engine
{
	struct Entity;
	struct Core
	{
		static std::shared_ptr<Core> initialize();
		void start();
		void stop();

		std::shared_ptr<Entity> addEntity();

	private:
		std::weak_ptr<Core> m_self;
		bool m_running;
		std::vector<std::shared_ptr<Entity> > m_entities;
		SDL_Window* m_window;
		SDL_GLContext m_context;
	};
}