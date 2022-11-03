#include "include/SDL.h"
#include <memory>
#include <vector>

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