/*
	Creates the main screen for the game to work
*/

#include "jellybeanengine/jellybeanengine.h"
#include <iostream>
#include <string>

using namespace JellyBean_Engine;

/*
*	This creates a struct named player from the component class. 
*	Here we can edit the entity component that creates the model
*	that will be displayed on screen.
*/
struct Player : Component
{
	Player() : m_angle(0) { }
	void onTick()
	{
		m_angle += 0.1f;

		getEntity()->getTransform()->setRotation(rend::vec3(0, m_angle, 0));
	}

private:
	float m_angle;
};

int main()
{
	/*
	*	We use shared pointers to initialise our core and to add entities
	*	into the screen. From the entities we can add components that we
	*	need, so for example the Player and Triangle Renderer.
	* 
	*	We also start the core from the main function
	*/
	std::shared_ptr<Core> core = Core::initialize();

	std::shared_ptr<Entity> e = core->addEntity();
	e->addComponent<Player>();
	e->addComponent<TriangleRenderer>();
	e->getTransform()->setPosition(rend::vec3(0, 0, -5));

	core->start();

	return 0;
}