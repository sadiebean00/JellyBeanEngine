#include "Core.h"
#include "Entity.h"
#include "Transform.h"

#include "rend/rend.h"


#include <memory>
#include <stdexcept>

/*
*	This is where we initialise SDL, AL as well as well as displaying 
*	the final window with the settings we have set in our initialise
*	function. Here we also have our error messages that will initialise 
*	if our program cannot load anything correctly.
*/
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

		ALCdevice* device = alcOpenDevice(NULL);

		if (!device)
		{
			throw std::runtime_error("Failed to open audio device");
		}

		ALCcontext* context = alcCreateContext(device, NULL);

		if (!context)
		{
			alcCloseDevice(device);
			throw std::runtime_error("Failed to create audio context");
		}

		if (!alcMakeContextCurrent(context))
		{
			alcDestroyContext(context);
			alcCloseDevice(device);
			throw std::runtime_error("Failed to make context current");
		}

		alListener3f(AL_POSITION, 0.0f, 0.0f, 0.0f);

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
		rtn->m_transform = rtn->addComponent<Transform>();

		m_entities.push_back(rtn);

		return rtn;
	}
}