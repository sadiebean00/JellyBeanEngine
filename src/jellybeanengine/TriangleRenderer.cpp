/*
	Creates the triangle renderer class
*/

#include "TriangleRenderer.h"

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

		r.render();
	}
}