#include "MainPlayer.h"

/*
*	This is my main player class where everything to do with the player
*	is called. Firstly, we call our onInit function. Through this
*	function we load our player's model as well as the texture used and
*	link them together.
* 
*	Secondly we have our onTick function. This handles all of the input
*	from the player, which will either move the player around or play
*	a sound bite depending on the option pressed.
*/

void MainPlayer::onInit()
{
	//std::shared_ptr<TriangleRenderer> triangle = getEntity()->addComponent<TriangleRenderer>();

	std::shared_ptr<Collision> collider = getEntity()->
		addComponent<Collision>();
	std::shared_ptr<Triggers> trigger = getEntity()->
		addComponent<Triggers>();
	std::shared_ptr<Model> model = getCore()->getResources()->
		load<Model>("D:/Uni Shit/Year 3/GEP/JellyBeanEngine/resources/HomerSimpson/homer_simpson");
	std::shared_ptr<Texture> tex = getCore()->getResources()->
		load<Texture>("D:/Uni Shit/Year 3/GEP/JellyBeanEngine/resources/HomerSimpson/homer.png");

	std::shared_ptr<RendererModel> modelrend = getEntity()->
		addComponent<RendererModel>(model);

	modelrend->setTexture(tex);
}

void MainPlayer::onTick()
{
	float speed = 0.5f;

	glm::vec3 direction;
	float yRotate = getEntity()->getComponent<Transform>()->getRotation().y;
	direction.x = glm::sin(glm::radians(yRotate));
	direction.y = 0;
	direction.z = glm::cos(glm::radians(yRotate));

	getCore()->getGameEnvironment()->calculateDeltaTme();
	
	if (getCore()->getController()->getKey(SDLK_w))
	{
		getEntity()->getTransform()->move(glm::vec3(0.0f, 0.0f, 25.0f) *
			getCore()->getGameEnvironment()->getDeltaTime());

		std::cout << "W key pressed" << std::endl;
	}
	

	if (getCore()->getController()->getKey(SDLK_s))
	{
		getEntity()->getTransform()->move(glm::vec3(0.0f, 0.0f, -25.0f)
			* getCore()->getGameEnvironment()->getDeltaTime());

		std::cout << "S key pressed" << std::endl;
	}

	if (getCore()->getController()->getKey(SDLK_d))
	{
		getEntity()->getTransform()->rotate(glm::vec3(0.0f, 80.0f, 0.0f)
			* getCore()->getGameEnvironment()->getDeltaTime());

		std::cout << "D key pressed" << std::endl;
	}

	if (getCore()->getController()->getKey(SDLK_a))
	{
		getEntity()->getTransform()->rotate(glm::vec3(0.0f, -80.0f, 0.0f)
			* getCore()->getGameEnvironment()->getDeltaTime());

		std::cout << "A key pressed" << std::endl;
	}

	std::shared_ptr<AudioSource> audio = getEntity()->addComponent<AudioSource>();

	if (getCore()->getController()->getKey(SDLK_b))
	{
		std::shared_ptr<AudioClip> a1 = getCore()->getResources()->load<AudioClip>
			("D:/Uni Shit/Year 3/GEP/JellyBeanEngine/resources/audio/beer11");

		audio->setClip(a1);

		std::cout << "Now Playing: Mmmm Beer" << std::endl;
	}

	if (getCore()->getController()->getKey(SDLK_e))
	{
		std::shared_ptr<AudioClip> a1 = getCore()->getResources()->load<AudioClip>
			("D:/Uni Shit/Year 3/GEP/JellyBeanEngine/resources/audio/evlhmer");

		audio->setClip(a1);
		
		std::cout << "Now Playing: Evil Homer" << std::endl;
	}

	if (getCore()->getController()->getKey(SDLK_c))
	{
		std::shared_ptr<AudioClip> a1 = getCore()->getResources()->load<AudioClip>
			("D:/Uni Shit/Year 3/GEP/JellyBeanEngine/resources/audio/doh1_y");

		audio->setClip(a1);

		std::cout << "Now Playing: D'oh!" << std::endl;
	}

	glm::vec3 heading = getEntity()->getTransform()->getRotation();
	glm::vec3 playerPos = getEntity()->getTransform()->getPosition();
	glm::vec3 offset(0.0f, -2.0f, -3.0f);

	getCore()->getCamera()->follow(playerPos, offset, heading);
}

void MainPlayer::onCollision(std::shared_ptr<Collision> c)
{
	std::cout << "trigger" << std::endl;
}

void MainPlayer::onUpdate()
{
	getEntity()->getTransform()->setPosition(newPos);
}