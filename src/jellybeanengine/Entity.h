#pragma once

#include <memory>
#include <vector>
#include "Transform.h"
#include "Exception.h"


namespace JellyBean_Engine
{
	struct Component;
	struct Transform;
	struct Core;
	struct Collision;

	/*
	*	This is my entity class in which stores the various components
	*	that need to be added as well as the ability to get the 
	*	components. The way we add these components is through a 
	*	template that can be reused for whatever component needs them.
	*/

	struct Entity
	{
		template <typename T>
		std::shared_ptr<T> addComponent()
		{
			std::shared_ptr<T> rtn = std::make_shared<T>();
			rtn->self = rtn;
			rtn->entity = self;

			components.push_back(rtn);

			rtn->onInit();

			return rtn;
		}
		
		template <typename T, typename A>
		std::shared_ptr<T> addComponent(A a)
		{
			std::shared_ptr<T> rtn = std::make_shared<T>(a);
			rtn->self = rtn;
			rtn->entity = self;

			components.push_back(rtn);

			rtn->onInit();

			return rtn;
		}

		template <typename T>
		std::shared_ptr<T> getComponent()
		{
			for (size_t ci = 0; ci < components.size(); ci++)
			{
				std::shared_ptr<T> rtn =
					std::dynamic_pointer_cast<T>(components.at(ci));
				if (rtn)
				{
					return rtn;
				}
			}
			throw Exception("Failed to obtain specified component");
		}

		std::shared_ptr<Core> getCore();

		std::shared_ptr<Transform> getTransform();

		std::shared_ptr<Component> getComponent();

		void tick();

		void display();

		void begin();

		void colliding(std::shared_ptr<Collision> c);

	private:
		friend struct JellyBean_Engine::Core;
		std::vector<std::shared_ptr<Component>> components;
		std::weak_ptr<Core> core;
		std::weak_ptr<Entity> self;
		std::weak_ptr<Transform> transform;
	};


}