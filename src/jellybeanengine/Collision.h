#pragma once

#include <memory>
#include "Component.h"


namespace JellyBean_Engine
{
	struct Core;
	struct Collision;

	/*
	*	This is my Collision class, inherited from the Component class.
	*	The collision class is what happens when the player collides
	*	with something. I did not get the chance to fully implement
	*	this class within the game, but if I did I would have wanted
	*	the entity that got collided with to disappear off of the
	*	screen. We do reference the Collision and Core classes.
	*/

	struct Collision : Component
	{
		void onInit();

		void onDestroy();

		bool isColliding(std::shared_ptr<Collision> _collider);

	private:
		friend struct JellyBean_Engine::Core;
		float m_radius;
	};
}