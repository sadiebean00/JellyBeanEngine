#include "Materials.h"

namespace JellyBean_Engine
{
	void Materials::onInit()
	{
		shader = std::make_shared<ShaderProgram>(getPath(), getPath());
	}
}