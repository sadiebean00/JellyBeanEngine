#include "jellybeanengine/jellybeanengine.h"
#include <iostream>
#include <string>

using namespace JellyBean_Engine;

struct Player : Component
{
	Player() : m_count(0) { }
	void onTick()
	{
		++m_count;
		//std::cout << "Ticking..." << std::endl;

		if (m_count > 10)
		{
			//getEntity()->kill();
			//getEntity()->getCore()->stop();
		}
	}

private:
	int m_count;
};

int main()
{
	std::shared_ptr<Core> core = Core::initialize();

	std::shared_ptr<Entity> e = core->addEntity();
	e->addComponent<Player>();
	e->addComponent<TriangleRenderer>();

	core->start();

	return 0;
}