#pragma once
#include "myScene.h"

MyScene::MyScene(GLFWwindow* window, InputHandler* H) : Scene(window, H)
{
	m_camera = new FirstPersonCamera();
	m_camera->attachHandler(m_window, m_handler);
	m_myShader = new Shader("..\\Shaders\\VertShader.glsl", "..\\Shaders\\FragShader.glsl");
	//cubeRota = gsl::vec3(0.0, 0.0, 0.0);
	makeVAO();
}

void MyScene::makeVAO()
{

	glCreateBuffers(1, &VBO);
	glNamedBufferStorage(VBO, sizeof(float) * vertexData.size(), vertexData.data(), GL_DYNAMIC_STORAGE_BIT);

	glCreateBuffers(1, &EBO);
	glNamedBufferStorage(EBO, sizeof(unsigned int) * cubeIndices.size(), cubeIndices.data(), GL_DYNAMIC_STORAGE_BIT);

	glCreateVertexArrays(1, &VAO);
	glVertexArrayVertexBuffer(VAO, 0, VBO, 0, sizeof(float) * 6);
	glVertexArrayElementBuffer(VAO, EBO);

	glEnableVertexArrayAttrib(VAO, 0);
	glEnableVertexArrayAttrib(VAO, 1);

	glVertexArrayAttribFormat(VAO, 0, 3, GL_FLOAT, GL_FALSE, 0);
	glVertexArrayAttribFormat(VAO, 1, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float));

	glVertexArrayAttribBinding(VAO, 0, 0);
	glVertexArrayAttribBinding(VAO, 1, 0);
}

void MyScene::update(float dt)
{
	m_camera->update(dt);
	render();
}

void MyScene::render()
{
	m_model = glm::mat4(1.0f);
	m_projection = m_camera->getProjectionMatrix();
	m_view = m_camera->getViewMatrix();
	m_myShader->use();

	m_myShader->setMat4("View", m_view);
	m_myShader->setMat4("Projection", m_projection);
	m_myShader->setMat4("Model", m_model);
	m_myShader->setVec3("viewPos", m_camera->getPosition());


	glm::vec3 pointLightPos = glm::vec3(-2.0f, 0.0f, 0.0f);  
	glm::vec3 pointLightColour = glm::vec3(1.0f, 0.0f, 0.0f);  
	glm::vec3 pointLightAtten = glm::vec3(1.0f, 0.22f, 0.02f); 

	m_myShader->setVec3("pointLightPos", pointLightPos);
	m_myShader->setVec3("pointLightColour", pointLightColour);
	m_myShader->setVec3("pointLightAtten", pointLightAtten);

	




	glBindVertexArray(VAO);
	glDrawElements(GL_TRIANGLES, cubeIndices.size(), GL_UNSIGNED_INT, 0);
	//glDrawArrays(GL_TRIANGLES, 0, 3);

	/*float vel = 1;
	if (m_handler->keyHasBeenPressed())
	{
		if (m_handler->isKeyPressed(GLFW_KEY_UP))
		{
			cubeRota = cubeRota + glm::vec3(-vel, 0.0, 0.0);
			m_model = glm::rotate(m_model, (float)(glfwGetTime() * 0.01), cubeRota);
		};
		
		if (m_handler->isKeyPressed(GLFW_KEY_DOWN))
		{
			cubeRota = cubeRota + glm::vec3(vel, 0.0, 0.0);
			m_model = glm::rotate(m_model, (float)(glfwGetTime() * 0.01), cubeRota);
		};

		if (m_handler->isKeyPressed(GLFW_KEY_LEFT))
		{
			cubeRota = cubeRota + glm::vec3(0.0, vel, 0.0);
			m_model = glm::rotate(m_model, (float)(glfwGetTime() * 0.01), cubeRota);
		};

		if (m_handler->isKeyPressed(GLFW_KEY_RIGHT))
		{
			cubeRota = cubeRota + glm::vec3(0.0, -vel, 0.0);
			m_model = glm::rotate(m_model, (float)(glfwGetTime() * 0.01), cubeRota);
		};
	
	}
	else
	{
		cubeRota = glm::vec3(0.0, 0.0, 0.0);
	}*/
	m_model = glm::translate(m_model, glm::vec3(5.0, 0.0, 0.0));
	m_model = glm::rotate(m_model, (float)(glfwGetTime() * 0.5), glm::vec3(1.0, 0.0, 0.0));
	m_myShader->setMat4("Model", m_model);
	
	glDrawElements(GL_TRIANGLES, vertexData.size(), GL_UNSIGNED_INT, 0);

	
}