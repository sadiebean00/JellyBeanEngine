#pragma once

#include <memory>
#include <vector>


namespace JellyBean_Engine
{
	struct Entity;
	struct Core;
	struct Transform;
	struct Collision;
	struct Controller;

	/*
	*	This is our Component class that holds all of the necessary
	*	components for the development of my engine. In order to 
	*	access these various commands, they need to be made public
	*	by using the shared_ptr<> values as well as declaring the
	*	various classes that we need.
	*/

	struct Component
	{
		std::shared_ptr<Entity> getEntity();

		std::shared_ptr<Core> getCore();

		std::shared_ptr<Controller> getController();

		std::weak_ptr<Entity> entity;

		std::weak_ptr<Component> self;

	private:

		friend struct JellyBean_Engine::Entity;

		virtual void onInit();
		virtual void onBegin();
		virtual void onTick();
		virtual void onDisplay();
		virtual void onCollision(std::shared_ptr<Collision> c);

		void tick();
		void display();
		void begin();
		void collision(std::shared_ptr<Collision> c);


	};
}