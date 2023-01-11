#include "Component.h"
#include <GLM/glm.hpp>
#include <GLM/gtc/matrix_transform.hpp>
#include <GLM/gtx/transform2.hpp>

namespace JellyBean_Engine
{
	struct Transform;
	struct Model;
	struct ShaderProgram;

	/*
	*	This is our Camera class header, which inherits from the 
	*	component class again. Here we set the follow for the 
	*	camera, the initialise as well as the destroy.
	* 
	*	As we need data from other classes, we make sure to know that
	*	this class gets data from the Core, Transform, Model and Shader
	*	Program classes.
	*/

	struct Camera : Component
	{
		Camera();

		void onInit();

		void onDestroy();

		void follow(glm::vec3 targetPos, glm::vec3 offset, glm::vec3 heading);

	private:
		friend struct JellyBean_Engine::Core;

		glm::vec3 playerPos;
		glm::vec3 playerHeading;
		glm::vec3 offset;

		glm::vec3 cameraPos;

		glm::mat4 view;
	};
}