#include "RendererModel.h"
#include "Core.h"
#include "Controller.h"
#include "Entity.h"
#include "Transform.h"
#include "Model.h"
#include "Resources.h"
#include "GameScreen.h"
#include "Camera.h"

namespace JellyBean_Engine
{
	RendererModel::RendererModel(std::shared_ptr<Model> _model)
	{

		model = _model;
		shader = std::make_shared<ShaderProgram>(
			"D:/Uni Shit/Year 3/GEP/JellyBeanEngine/src/simpleVert.txt", 
			"D:/Uni Shit/Year 3/GEP/JellyBeanEngine/src/simpleFrag.txt");
	}


	void RendererModel::onDisplay()
	{
		glUseProgram(shader->getId());
		glBindVertexArray(model->vao->getId());

		shader->setMat4("u_Model", getEntity()->getTransform()->getModel());
		shader->setMat4("u_View", glm::inverse(getCore()->getCamera()->getEntity()
			->getTransform()->getModel()));
		shader->setMat4("u_Projection", glm::perspective(glm::radians(45.0f),
			(float)getCore()->getGameScreen()->getWidth() / (float)getCore()
			->getGameScreen()->getHeight(), 0.1f, 100.0f));
		shader->setInt("u_Texture", 0);

		glBindTexture(GL_TEXTURE_2D, tex->getId());

		glDrawArrays(GL_TRIANGLES, 0, model->vao->getVertCount());

		glBindVertexArray(0);
		glUseProgram(0);


	}

	void RendererModel::setModel(std::string path)
	{
		getCore()->getResources()->load<Model>(path + ".obj");
	}

	void RendererModel::setModel(std::shared_ptr<Model> _model)
	{
		model = _model;
	}

	void RendererModel::setMaterial(std::shared_ptr<Materials> _mat)
	{
		shader = _mat->shader;
	}

	void RendererModel::setTexture(std::shared_ptr<Texture> _tex)
	{
		tex = _tex;
	}

	void RendererModel::onBegin() {}


}