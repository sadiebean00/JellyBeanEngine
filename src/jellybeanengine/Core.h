#pragma once

#include <memory>
#include <vector>
#include <SDL.h>


namespace JellyBean_Engine
{
	struct Entity;
	struct GameEnvironment;
	struct GameScreen;
	struct Controller;
	struct Transform;
	struct Collision;
	struct Triggers;
	struct Resources;
	struct Camera;

	/*
	*	This is the Core header, where everything that is needed in
	*	order for the game engine to fully function properly. This
	*	is also where the SDL screen is called and created. We also
	*	register the camera and collisions for the game.
	*/

	struct Core
	{
		static std::shared_ptr<Core> initialize();

		std::shared_ptr<Entity> addEntity();

		std::shared_ptr<GameEnvironment> getGameEnvironment();

		std::shared_ptr<Controller> getController();

		std::shared_ptr<GameScreen> getGameScreen();

		std::shared_ptr<Resources> getResources();

		std::shared_ptr<Camera> getCamera();

		SDL_Window* getWindow();

		void registerCollider(std::shared_ptr<Collision> sphere);

		void unregisterCollider(Collision* sphere);

		void registerCamera(std::shared_ptr<Camera> cam);

		void unregisterCamera(Camera* cam);

		void start();

		void stop();

	private:
		friend struct Triggers;
		std::vector<std::shared_ptr<Entity> > entities;
		std::weak_ptr<Core> self;
		std::shared_ptr<GameScreen> gamescreen;
		std::shared_ptr<Controller> controller;
		std::shared_ptr<Resources> resources;
		std::vector<std::shared_ptr <Collision> > collisions;
		std::shared_ptr<Camera>  camera;

		bool running;
		SDL_Window* window;
		std::shared_ptr<GameEnvironment> gameenvironment;


	};
}