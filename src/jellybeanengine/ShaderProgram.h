#pragma once

#include <GL/glew.h>
#include <memory>
#include <vector>
#include <iostream>
#include <string>
#include <GLM/glm.hpp>
#include <GLM/gtc/matrix_transform.hpp>
#include <GLM/gtc/type_ptr.hpp>
#include <GLM/gtx/transform.hpp> 
#include <string>
#include "VertexArray.h"

namespace JellyBean_Engine
{
	/*
	*	The Shader Program relies on data that is loaded in from our 
	*	shader files. These files then alter the data based on how
	*	much data is in the files and the sort of data that is stored 
	*	there. 
	* 
	*	We need a Shader Program within our game in order to properly 
	*	load our textures into the game.
	*/

	struct ShaderProgram
	{
	public:
		ShaderProgram(std::string vertexPath, std::string fragmentPath);

		~ShaderProgram();
		GLuint getId();

		void setBool(const std::string& name, bool value) const;

		void setInt(const std::string& name, int value) const;

		void setFloat(const std::string& name, float value) const;

		void setVec2(const std::string& name, const glm::vec2& value) const;

		void setVec2(const std::string& name, float x, float y) const;

		void setVec3(const std::string& name, const glm::vec3& value) const;

		void setVec3(const std::string& name, float x, float y, float z) const;

		void setVec4(const std::string& name, const glm::vec4& value) const;

		void setVec4(const std::string& name, float x, float y, float z, float w);

		void setMat2(const std::string& name, const glm::mat2& mat) const;

		void setMat3(const std::string& name, const glm::mat3& mat) const;

		void setMat4(const std::string& name, const glm::mat4& mat) const;

	private:
		GLuint id;
		GLuint fragmentShaderId;
		GLuint vertexShaderId;
		void errorCheck(GLuint shader, std::string type);
		bool CheckShaderCompiled(GLuint shader);

	};

}