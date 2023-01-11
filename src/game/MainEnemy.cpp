#include "MainEnemy.h"

/*
*	This is our Main Enemy source code. Here we define the initialising
*	for the enemy, as well as setting the spin for the enemy. This 
*	allows for the enemy (or collectible as my original design had)
*	to spin and distract the player.
* 
*	For debugging purposes, I included some output for the console to
*	help me figure out if the collisions were setup properly, a bit 
*	like my controller outputting text to help see the controls work
*	properly.
*/

MainEnemy::MainEnemy(bool _spin)
{
	spin = _spin;
	hasEntered = false;
}

void MainEnemy::onInit()
{
	std::shared_ptr<Collision> collider = getEntity()->
		addComponent<Collision>();

	std::shared_ptr<Model> model = getCore()->getResources()->
		load<Model>("D:/Uni Shit/Year 3/GEP/JellyBeanEngine/resources/DuffCap/spr_duffbottleca");

	std::shared_ptr<Texture> tex = getCore()->getResources()->
		load<Texture>("D:/Uni Shit/Year 3/GEP/JellyBeanEngine/resources/DuffCap/spr_duffbottleca.png");

	modelrend = getEntity()->addComponent<RendererModel>(model);
	modelrend->setTexture(tex);
}

void MainEnemy::onTick()
{
	if (spin)
	{
		getEntity()->getTransform()->rotate(glm::vec3(getCore()
			->getGameEnvironment()->getDeltaTime() * 100));
	}
}

void MainEnemy::onCollision(std::shared_ptr<Collision> c)
{
	if (!hasEntered)
	{
		hasEntered = true;
		std::cout << "Duff cap collected"  << std::endl;
	}
}