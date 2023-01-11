#include "TriangleRenderer.h"
#include "Core.h"
#include "Controller.h"
#include "Entity.h"
#include "Transform.h"
#include "Camera.h"

namespace JellyBean_Engine
{
	TriangleRenderer::TriangleRenderer()
	{
		std::shared_ptr<VertexBuffer> positionsVbo = std::make_shared<VertexBuffer>();
		positionsVbo->add(glm::vec3(0.0f, 0.5f, 0.0f));
		positionsVbo->add(glm::vec3(-0.5f, -0.5f, 0.0f));
		positionsVbo->add(glm::vec3(0.5f, -0.5f, 0.0f));

		std::shared_ptr<VertexBuffer> colorVbo = std::make_shared<VertexBuffer>();
		colorVbo->add(glm::vec4(1.0f, 0.0f, 0.0f, 1.0f));
		colorVbo->add(glm::vec4(0.0f, 1.0f, 0.0f, 1.0f));
		colorVbo->add(glm::vec4(0.0f, 0.0f, 1.0f, 1.0f));

		vao = std::make_shared<VertexArray>();
		vao->setBuffer(0, positionsVbo);
		vao->setBuffer(1, colorVbo);

		shader = std::make_shared<ShaderProgram>(
			"D:/Uni Shit/Year 3/GEP/JellyBeanEngine/src/simpleVert.txt", 
			"D:/Uni Shit/Year 3/GEP/JellyBeanEngine/src/whiteFragmentShader.txt");
	}

	void TriangleRenderer::onTick(){}

	void TriangleRenderer::onDisplay()
	{
		glUseProgram(shader->getId());
		glBindVertexArray(vao->getId());

		shader->setMat4("u_Model", getEntity()->getTransform()->getModel());
		shader->setMat4("u_Projection", glm::perspective(glm::radians(45.0f),
			800.0f / 600.0f, 0.1f, 100.0f));
		shader->setMat4("u_View", glm::inverse(getCore()->getCamera()->getEntity()->getTransform()->getModel()));

		glDrawArrays(GL_TRIANGLES, 0, 3);

		glBindVertexArray(0);
		glUseProgram(0);
	}

	void TriangleRenderer::onBegin(){}


}