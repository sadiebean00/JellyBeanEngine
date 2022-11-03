#pragma once

#include <memory>

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

