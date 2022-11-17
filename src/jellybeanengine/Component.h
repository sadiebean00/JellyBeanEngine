#pragma once

#include <memory>
#include <string>

/*
*	This is our component class which creates a whole new struct named
*	component. Here we have our onTick and onDisplay functions. We also
*	utilise the Entity class which we need in order to get our Entity
*	components.
*/
namespace JellyBean_Engine
{
	struct Entity;
	
	struct Component
	{
		virtual void onTick();
		virtual void onDisplay();

		std::shared_ptr<Entity> getEntity();

	private:
		friend struct Entity;

		std::weak_ptr<Entity> m_entity;

		void tick();
		void display();
	};
}

