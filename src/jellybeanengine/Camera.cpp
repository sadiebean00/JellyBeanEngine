#include "Camera.h"
#include "ShaderProgram.h"
#include "Core.h"
#include "Entity.h"
#include "Transform.h"
#include "Model.h"

namespace JellyBean_Engine
{
	/*
	*	This sets the view matrix for the camera.
	*/

	Camera::Camera()
	{
		view = glm::mat4(1.0f);
	}

	/*
	*	This registers the camera when the engine is initiated for the
	*	first time.
	*/

	void Camera::onInit()
	{
		getCore()->registerCamera(getEntity()->getComponent<Camera>());
	}

	/*
	*	This destroys the camera entity. This is called when the
	*	game screen is exited from.
	*/

	void Camera::onDestroy()
	{
		getCore()->unregisterCamera(this);
	}

	/*
	*	This is my attempt at getting the camera to follow the player
	*	behind them rather above them. However, I could not get this 
	*	functioning in enough time.
	*/

	void Camera::follow(glm::vec3 targetPos, glm::vec3 offset, glm::vec3 heading)
	{
		this->playerPos = targetPos;
		playerHeading = heading;
		this->offset = offset;

		glm::vec3 target = targetPos + offset;

		float lerp = 0.1f;

		glm::vec3 pos = cameraPos;
		glm::vec3 diff(0.0f);

		diff = (target - pos) * 0.1f;
		cameraPos += diff;
	}
}