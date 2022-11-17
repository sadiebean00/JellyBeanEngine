#include "Entity.h"
#include "Component.h"
#include "Core.h"
#include "Transform.h"

/*
*	This is where we set the tick function for the components to be running 
*	through a for loop. A similar method takes place for the display function
*	too. The getCore and getTransform both use lock methods to stop any
*	potential leakages when it comes to the program.
*/
namespace JellyBean_Engine
{
	void Entity::tick()
	{
		for (size_t ci = 0; ci < m_components.size(); ++ci)
		{
			m_components.at(ci)->tick();
		}
	}

	void Entity::display()
	{
		for (size_t ci = 0; ci < m_components.size(); ++ci)
		{
			m_components.at(ci)->display();
		}
	}

	std::shared_ptr<Core> Entity::getCore()
	{
		return m_core.lock();
	}

	std::shared_ptr<Transform> Entity::getTransform()
	{
		return m_transform.lock();
	}
}