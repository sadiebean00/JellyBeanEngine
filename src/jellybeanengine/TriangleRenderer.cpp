/*
*	The Triangle Render is used to display the triangle through the rend
*	libraries and calls sets it to be a certain mesh. We also have our 
*	onDisplay function being used to set the renderer for the screen to
*	be at the window resolution. We then set the renderer and mesh before
*	changing the projection and model. We then render the triangle.
*/

#include "TriangleRenderer.h"
#include "Entity.h"
#include "Transform.h"

namespace JellyBean_Engine
{
	TriangleRenderer::TriangleRenderer() :
		m_mesh(rend::Mesh::TRIANGLE),
		m_shader(rend::Shader::BASIC)
	{

	}

	void TriangleRenderer::onDisplay()
	{
		rend::Renderer r(640, 480);

		r.shader(&m_shader);
		r.mesh(&m_mesh);

		r.projection(rend::perspective(rend::radians(45.0f), 1.0f, 0.1f, 100.0f));
		r.model(getEntity()->getTransform()->getModel());

		r.render();
	}
}