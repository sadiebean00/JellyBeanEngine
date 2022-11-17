#pragma once

#include <rend/rend.h>

#include "Component.h"

namespace JellyBean_Engine
{
	/*
	*	The Transform class is created from the component class as a struct.
	*	We initialise the functions setPosition and setRotation here, as well
	*	as getModel.
	*/
	struct Transform : Component
	{
		Transform();

		rend::mat4 getModel();

		void setPosition(const rend::vec3& _position);
		void setRotation(const rend::vec3& _rotation);

	private:
		rend::vec3 m_position;
		rend::vec3 m_rotation;
		rend::vec3 m_scale;
	};
}