#include "Component.h"

#include "rend/rend.h"

/*
*	This is where the triangle renderer is created for the screen to be
*	displayed. We reference our rend library in order to correctly load
*	in the meshes and shaders. We also set the onDisplay function here
*	for the triangle to be displayed correctly on screen.
*/
namespace JellyBean_Engine
{
	struct TriangleRenderer : public Component
	{
		TriangleRenderer();

	private:
		rend::Mesh m_mesh;
		rend::Shader m_shader;

		void onDisplay();
	};
}