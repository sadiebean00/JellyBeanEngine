#include "Core.h"
#include "Entity.h"
#include <GL/glew.h>
#include "GameScreen.h"
#include "GameEnvironment.h"
#include <iostream>
#include "TriangleRenderer.h"
#include "Controller.h"
#include "Transform.h"
#include "Resource.h"
#include "Resources.h"
#include "Camera.h"

#include <AL/al.h>
#include <AL/alc.h>


namespace JellyBean_Engine
{
	std::shared_ptr<Core> Core::initialize()
	{
		std::shared_ptr<Core> rtn = std::make_shared<Core>();
		rtn->self = rtn;
		rtn->running = false;
		rtn->gamescreen = std::make_shared<GameScreen>();
		rtn->resources = std::make_shared<Resources>();
		rtn->gameenvironment = std::make_shared<GameEnvironment>();
		rtn->controller = std::make_shared<Controller>();

		if (SDL_Init(SDL_INIT_VIDEO) < 0)
		{
			throw std::exception();
		}

		rtn->window = SDL_CreateWindow("JellyBean Engine",
			SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
			rtn->gamescreen->getWidth(), rtn->gamescreen->getHeight(),
			SDL_WINDOW_RESIZABLE | SDL_WINDOW_OPENGL);

		if (!SDL_GL_CreateContext(rtn->window))
		{
			throw std::exception();
		}
		if (glewInit() != GLEW_OK)
		{
			throw std::exception();
		}

		ALCdevice* device = alcOpenDevice(NULL);
		if (!device)
		{
			throw std::exception();
		}
		ALCcontext* context = alcCreateContext(device, NULL);
		if (!context)
		{
			alcCloseDevice(device);
			throw std::exception();
		}
		if (!alcMakeContextCurrent(context))
		{
			alcDestroyContext(context);
			alcCloseDevice(device);
			throw std::exception();
		}

		return rtn;
	}

	std::shared_ptr<Entity> Core::addEntity()
	{
		std::shared_ptr<Entity> rtn = std::make_shared<Entity>();
		rtn->self = rtn;
		rtn->core = self;
		rtn->transform = rtn->addComponent<Transform>();
		entities.push_back(rtn);
		return rtn;
	}

	std::shared_ptr<GameEnvironment> Core::getGameEnvironment()
	{
		return gameenvironment;
	}

	std::shared_ptr<Controller> Core::getController()
	{
		return controller;
	}

	SDL_Window* Core::getWindow()
	{
		return window;
	}

	std::shared_ptr<GameScreen> Core::getGameScreen()
	{
		return gamescreen;
	}

	std::shared_ptr<Resources> Core::getResources()
	{
		return resources;
	}

	std::shared_ptr<Camera> Core::getCamera()
	{
		return camera;
	}

	void Core::unregisterCamera(Camera* cam)
	{
		camera.reset();
	}


	void Core::registerCollider(std::shared_ptr<Collision> sphere)
	{
		collisions.push_back(sphere);
	}

	void Core::unregisterCollider(Collision* sphere)
	{
		for (size_t ci = 0; ci < collisions.size(); ci++)
		{
			if (collisions[ci].get() == sphere)
			{
				collisions.erase(collisions.begin() + ci);
				ci--;
			}
		}
	}

	void Core::registerCamera(std::shared_ptr<Camera> cam)
	{
		camera = cam;
	}

	void Core::start()
	{
		running = true;

		//on Start
		for (size_t ei = 0; ei < entities.size(); ei++)
		{
			entities.at(ei)->begin();
		}

		while (running)
		{
			SDL_Event event;
			while (SDL_PollEvent(&event))
			{
				if (event.type == SDL_QUIT)
				{
					running = false;
				}

				else if (event.type == SDL_KEYDOWN)
				{
					controller->keyCodes.push_back(event.key.keysym.sym);
				}

				else if (event.type == SDL_KEYUP)
				{
					controller->removeKey(event.key.keysym.sym);
				}
			}
			
			for (size_t ei = 0; ei < entities.size(); ei++)
			{
				entities.at(ei)->tick();
			}

			glClearColor(0.0f, 1.0f, 1.0f, 1.0f);
			glEnable(GL_DEPTH_TEST);
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

			for (size_t ei = 0; ei < entities.size(); ei++)
			{
				entities.at(ei)->display();
			}

			SDL_GL_SwapWindow(window);
		}
	}

	void Core::stop()
	{
		running = false;
	}

}