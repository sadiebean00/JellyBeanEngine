#pragma once
#include "Resource.h"

namespace JellyBean_Engine
{

	struct VertexArray;
	struct RendererModel;

	/*
	*	This is the model class which stores the vao for the model as
	*	well as the path for the model. We told our program to only look
	*	for model paths that end in '.obj', as that is what most models
	*	formats are.
	*/

	struct Model : Resource
	{
		void onInit();

	private:
		friend struct JellyBean_Engine::RendererModel;
		std::shared_ptr<VertexArray> vao;
	};

}