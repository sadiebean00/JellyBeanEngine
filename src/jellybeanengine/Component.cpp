#include "Component.h"
#include "Entity.h"

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