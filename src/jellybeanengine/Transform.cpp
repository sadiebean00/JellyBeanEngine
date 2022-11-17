#include "Transform.h"

namespace JellyBean_Engine
{
	Transform::Transform() : m_scale(1, 1, 1)
	{

	}

	/*
	*	This gets the model for the transformation by setting the translate
	*	to be where the matrix for rtn is as well as the position. We can
	*	then set the rotation of the model to be specifically set to the 
	*	different axis (x, y & z). Finally, we also set the scale to be
	*	equivalent to the m_scale variable that we have.
	*/
	rend::mat4 Transform::getModel()
	{
		rend::mat4 rtn = rend::mat4(1.0f);

		rtn = rend::translate(rtn, m_position);
		rtn = rend::rotate(rtn, rend::radians(m_rotation.y), rend::vec3(0, 1, 0));
		rtn = rend::rotate(rtn, rend::radians(m_rotation.x), rend::vec3(1, 0, 0));
		rtn = rend::rotate(rtn, rend::radians(m_rotation.z), rend::vec3(0, 0, 1));

		rtn = rend::scale(rtn, m_scale);

		return rtn;
	}

	/*
	*	This sets the position of the transform variable to be equivalent
	*	to a vec3 that we set earlier.
	*/
	void Transform::setPosition(const rend::vec3& _position)
	{
		m_position = _position;
	}

	/*
	*	This sets the rotation of the transform variable to be equivalent
	*	to a vec3 that we set earlier.
	*/
	void Transform::setRotation(const rend::vec3& _rotation)
	{
		m_rotation = _rotation;
	}
}