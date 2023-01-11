#include "MainPlayer.h"
#include "MainEnemy.h"
#include "Audio.h"

#include <iostream>
#include <string>

using namespace JellyBean_Engine;

int main()
{
	/*
	*	This is the main process for the game loop. We start off by
	*	initialising our core that we created. Once the core has been
	*	initialised, we can start adding new entities onto our screen.
	* 
	*	For the purposes of this demo, I have only added two entities,
	*	a player entity as well as an enemy entity. Once these two
	*	entities have been included, we then load up the camera so that
	*	our players can see what we are doing. 
	* 
	*	Finally, we start the core to see the full event of our game
	*	engine.
	*/

	std::shared_ptr<Core> core = Core::initialize();

	std::shared_ptr<Entity> playerEntity = core->addEntity();
	std::shared_ptr<Component> playerComponent = playerEntity->addComponent<Component>();
	playerEntity->addComponent<MainPlayer>();
	playerEntity->addComponent<Camera>();
	playerEntity->getTransform()->setPosition(glm::vec3(0.0f, -15.0f, -80.0f));

	glm::vec3 playerPos = playerEntity->getTransform()->getPosition();
	glm::vec3 offset(0.0f);
	glm::vec3 playerHeading = playerEntity->getTransform()->getRotation();

	std::shared_ptr<Entity> enemyEntity = core->addEntity();
	enemyEntity->addComponent<MainEnemy>(false);
	enemyEntity->getTransform()->setPosition(glm::vec3(0.0f, 0.0f, -25.0f));
	enemyEntity->getTransform()->setScale(glm::vec3(3.0f));

	std::shared_ptr<Entity> camera = core->addEntity();
	camera->addComponent<Camera>();
	camera->getTransform()->setPosition(glm::vec3(0.0f, 20.0f, 15.0f));
	camera->getTransform()->setRotation(glm::vec3(-25.0f, 0.0f, 0.0f));

	playerEntity->getCore()->getCamera()->
		follow(playerPos, offset, playerHeading);

	core->start();

	return 0;
}