#include "Resource.h"
#include "ShaderProgram.h"
#include <memory>
#pragma once
namespace JellyBean_Engine
{
	struct RendererModel;
	struct ShaderProgram;

	///This is similar to Unity's material system, it lets the user add a shader to a gameobject such as a model.

	struct Materials : Resource
	{
		void onInit();

	private:
		friend struct JellyBean_Engine::RendererModel;
		std::shared_ptr<ShaderProgram> shader;
	};
}