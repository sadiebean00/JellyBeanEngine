/**
 *	Creates the component class. Here we call the onTick function (which
 *	shows how many ticks it takes for the engine to work correctly). We
 *	also have our onDisplay function, which takes the display function
 *	and tells us that the component is displayed. We also have our 
 *	getEntity component which locks our entities into place to prevent
 *	leaks in our system.
 */
#include "Component.h"
#include "Entity.h"

#include "AL/al.h"
#include "AL/alc.h"


namespace JellyBean_Engine
{
	void Component::onTick()
	{

	}

	void Component::onDisplay()
	{

	}

	void Component::tick()
	{
		onTick();
	}

	void Component::display()
	{
		onDisplay();
	}

	std::shared_ptr<Entity> Component::getEntity()
	{
		return m_entity.lock();
	}
}