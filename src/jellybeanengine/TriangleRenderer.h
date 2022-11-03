#include "Component.h"

#include "rend/rend.h"

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