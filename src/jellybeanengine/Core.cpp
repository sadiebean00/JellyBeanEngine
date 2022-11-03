#include "Core.h"
#include "Entity.h"
#include "rend/rend.h"

#include <memory>
#include <stdexcept>

namespace JellyBean_Engine
{
	std::shared_ptr<Core> Core::initialize()
	{
		std::shared_ptr<Core> rtn = std::make_shared<Core>();

		rtn->m_self = rtn;
		rtn->m_running = false;

		if (SDL_Init(SDL_INIT_VIDEO) < 0)
		{
			throw std::runtime_error("Failed to initialize SDL");
		}

		rtn->m_window = SDL_CreateWindow("SDL Window",
			SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
			640, 480, SDL_WINDOW_RESIZABLE | SDL_WINDOW_OPENGL);

		if (!rtn->m_window)
		{
			throw std::runtime_error("Failed to create window");
		}

		rtn->m_context = SDL_GL_CreateContext(rtn->m_window);

		if (!rtn->m_context)
		{
			throw std::runtime_error("Failed to create context");
		}

		return rtn;
	}

	void Core::start()
	{
		m_running = true;
		SDL_Event event = { 0 };

		while (m_running)
		{
			while (SDL_PollEvent(&event))
			{
				if (event.type == SDL_QUIT)
				{
					m_running = false;
				}
			}
			for (size_t ei = 0; ei < m_entities.size(); ++ei)
			{
				m_entities.at(ei)->tick();
			}
			
			rend::Renderer r(640, 480);
			r.clear();

			for (size_t ei = 0; ei < m_entities.size(); ++ei)
			{
				m_entities.at(ei)->display();
			}

			SDL_GL_SwapWindow(m_window);
		}
	}

	void Core::stop()
	{
		m_running = false;
	}

	std::shared_ptr<Entity> Core::addEntity()
	{
		std::shared_ptr<Entity> rtn = std::make_shared<Entity>();
		rtn->m_core = m_self;
		rtn->m_self = rtn;
		m_entities.push_back(rtn);

		return rtn;
	}
}