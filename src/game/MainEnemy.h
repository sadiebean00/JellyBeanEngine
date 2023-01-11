#pragma once

#include <jellybeanengine/jellybeanengine.h>

using namespace JellyBean_Engine;

/*
*	This is the header file for the Main Enemy class, which inherits 
*	from the component class. Here we reference from our Model Renderer
*	class to tell our calss how we render the model, as well as the 
*	Model class to get the path for the model. We also have our texture
*	class that references textures and shaders, so our model isn't 
*	black and white.
*/

struct MainEnemy : Component
{
	MainEnemy(bool _spin);

	void onInit();
	void onTick();
	void onCollision(std::shared_ptr<Collision> c);

private:
	std::shared_ptr<RendererModel> modelrend;

	std::shared_ptr<Model> lardLad;
	std::shared_ptr<Texture> lardLadTex;

	bool spin;
	bool hasEntered;
};