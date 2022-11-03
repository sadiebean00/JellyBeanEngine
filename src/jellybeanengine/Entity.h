#include <vector>
#include <memory>

namespace JellyBean_Engine
{
	struct Core;
	struct Component;

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

	private:
		friend struct Core;

		std::weak_ptr<Core> m_core;
		std::weak_ptr<Entity> m_self;

		bool m_alive;
		std::vector<std::shared_ptr<Component> > m_components;

		void tick();
		void display();
	};
}