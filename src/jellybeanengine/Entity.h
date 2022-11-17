#include <vector>
#include <memory>

/*
*	This is where we create the entity class for our game engine. Here
*	we add components to the game, as well as getting our core and getting
*	our transform components. We also see if our entity class is alive,
*	as well as having tick and display components.
*/
namespace JellyBean_Engine
{
	struct Core;
	struct Component;
	struct Transform;

	struct Entity
	{
		template <typename T>
		std::shared_ptr<T> addComponent()
		{
			std::shared_ptr<T> rtn = std::make_shared<T>();
			rtn->m_entity = m_self;
			m_components.push_back(rtn);

			return rtn;
		}

		std::shared_ptr<Core> getCore();
		std::shared_ptr<Transform> getTransform();

	private:
		friend struct Core;

		std::weak_ptr<Core> m_core;
		std::weak_ptr<Entity> m_self;

		bool m_alive;
		std::vector<std::shared_ptr<Component> > m_components;
		std::weak_ptr<Transform> m_transform;

		void tick();
		void display();
	};
}