#include "Collision.h"

#include "Core.h"
#include "Entity.h"
#include <GLM/glm.hpp>

namespace JellyBean_Engine
{
	/*
	*	This intiates the collision for the game when the engine is 
	*	started.
	*/

	void Collision::onInit()
	{
		getCore()->registerCollider(getEntity()->getComponent<Collision>());
		m_radius = 1.0f;
	}

	/*
	*	This destroys the collision for the game, normally when the 
	*	game screen is exited from.
	*/

	void Collision::onDestroy()
	{
		getCore()->unregisterCollider(this);
	}

	/*
	*	This double checks whether the game object has has a collision.
	*/

	bool Collision::isColliding(std::shared_ptr<Collision> _collider)
	{
		float distance = glm::distance(getEntity()->getTransform()->getPosition(), _collider->getEntity()->getTransform()->getPosition());
		float rad = m_radius + _collider->m_radius;
		if (distance < rad)
		{
			return true;
		}
		return false;
	}
}