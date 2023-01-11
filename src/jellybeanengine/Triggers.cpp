#include "Triggers.h"
#include "Core.h"
#include "Entity.h"
#include "Collision.h"

namespace JellyBean_Engine
{
	void Triggers::onTick()
	{
		std::shared_ptr<Collision> c = getEntity()->getComponent<Collision>();

		std::vector<std::shared_ptr<Collision>>& collisions = getCore()->collisions;

		for (size_t ci = 0; ci < collisions.size(); ci++)
		{
			if (collisions.at(ci) == c) continue;

			if (c->isColliding(collisions.at(ci)))
			{
				getEntity()->colliding(collisions.at(ci));
				collisions.at(ci)->getEntity()->colliding(c);
			}
		}
	}

}