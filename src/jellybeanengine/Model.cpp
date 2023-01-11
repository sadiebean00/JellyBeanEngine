#include "Model.h"
#include "VertexArray.h"

namespace JellyBean_Engine
{
	void Model::onInit()
	{
		vao = std::make_shared<VertexArray>(getPath() + ".obj");
	}
}