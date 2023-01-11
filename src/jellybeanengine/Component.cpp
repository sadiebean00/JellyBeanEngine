#pragma once

#include "Core.h"
#include "Entity.h"
#include "Component.h"
#include "Transform.h"

namespace JellyBean_Engine
{
	std::shared_ptr<Entity> Component::getEntity()
	{
		return entity.lock();
	}

	std::shared_ptr<Core> Component::getCore()
	{
		return entity.lock()->getCore();
	}

	void Component::onInit(){}
	void Component::onBegin(){}
	void Component::onTick(){}
	void Component::onDisplay(){}
	void Component::onCollision(std::shared_ptr<Collision> c){}

	void Component::tick()
	{
		onTick();
	}

	void Component::display()
	{
		onDisplay();
	}

	void Component::begin()
	{
		onBegin();
	}

	void Component::collision(std::shared_ptr<Collision> c)
	{
		onCollision(c);
	}

	std::shared_ptr<Controller> Component::getController()
	{
		return getCore()->getController();
	}
}