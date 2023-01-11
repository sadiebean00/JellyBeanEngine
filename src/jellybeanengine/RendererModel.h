#pragma once

#include <string>
#include "GL/glew.h"
#include "SDL.h"
#include <GLM/glm.hpp>
#include <GLM/gtc/matrix_transform.hpp>
#include <GLM/gtc/type_ptr.hpp>
#include <GLM/gtx/transform.hpp> 
#include <exception>
#include <iostream>
#include <memory>
#include "Component.h"
#include "VertexArray.h"
#include "VertexBuffer.h"
#include "ShaderProgram.h"
#include "Materials.h"
#include "Texture.h"

namespace JellyBean_Engine
{

	struct VertexArray;
	struct ShaderProgram;
	struct Transform;
	struct Model;
	struct Materials;

	/*
	*	Here this sets our model renderer up. In order for this to 
	*	fully work, we need to access the model path from the model
	*	class. We also need to link our vertex array so the class 
	*	knows how many arrays we need, as well as our shader program
	*	so that our textures work fully with the model. We also have the
	*	option to setup materials with the model too.
	*/

	struct RendererModel : Component
	{
		RendererModel(std::shared_ptr<Model> _model);

		void setModel(std::string _path);

		void setModel(std::shared_ptr<Model> _model);

		void setMaterial(std::shared_ptr<Materials> _mat);

		void setTexture(std::shared_ptr<Texture> _tex);

		void onDisplay();

		void onBegin();

	private:
		friend struct JellyBean_Engine::Core;
		std::shared_ptr<ShaderProgram> shader;
		std::shared_ptr<VertexArray> vao;
		std::shared_ptr<Model> model;
		std::shared_ptr<Texture> tex;
		std::shared_ptr<Materials> mat;

	};


}