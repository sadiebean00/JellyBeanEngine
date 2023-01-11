#include <jellybeanengine/jellybeanengine.h>

using namespace JellyBean_Engine;

/*
*	Like the enemy class, the Main Player class inherits from the 
*	component class and references the model renderer, model and 
*	texture classes. Unlike the enemy class, we put in the basis for
*	collision between the two classes. However, due to time 
*	constraints I could not complete this in time.
*/

struct MainPlayer : Component
{
	void onInit();
	void onTick();
	void onCollision(std::shared_ptr<Collision> c);
	void onUpdate();

	glm::vec3 currentPos;
	glm::vec3 newPos;

};