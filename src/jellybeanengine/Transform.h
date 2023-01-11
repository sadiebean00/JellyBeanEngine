#pragma once
#include <GLM/glm.hpp>
#include "Component.h"

namespace JellyBean_Engine
{
	/*
	*	This is the Transform class, which handles the movements of the
	*	player and camera by having three main functions. Anything to
	*	do with position, adjusts where the player or camera will be 
	*	located on the game screen.
	* 
	*	The rotation is responsible for the rotation of the entity.
	*	The scale is responsible for the scale of the entity. All of
	*	these can be adjusted to suit the needs of the developer.
	*/

	struct Transform : Component
	{
		Transform();

		glm::mat4 getModel();

		void setPosition(glm::vec3 _position);

		void setRotation(glm::vec3 _rotation);

		void setScale(glm::vec3 _scale);

		void move(float _amount);

		void move(glm::vec3 _amount);

		void rotate(glm::vec3 _amount);

		glm::vec3 getRotation();

		glm::vec3 getScale();

		glm::vec3 getPosition();

	private:
		friend struct JellyBean_Engine::Entity;
		glm::vec3 position;
		glm::vec3 rotation;
		glm::vec3 scale;

		float speed = 0.5f;
	};
}