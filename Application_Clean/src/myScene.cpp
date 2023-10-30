#pragma once
#include "myScene.h"

MyScene::MyScene(GLFWwindow* window, InputHandler* H) : Scene(window, H)
{
	m_camera = new FirstPersonCamera();
	m_camera->attachHandler(m_window, m_handler);
	m_myShader = new Shader("..\\Shaders\\VertShader.glsl", "..\\Shaders\\FragShader.glsl");
	makeVAO();
}

void MyScene::makeVAO()
{

	glCreateBuffers(1, &VBO);
	glNamedBufferStorage(VBO, sizeof(float) * 18, vertexData, GL_DYNAMIC_STORAGE_BIT);

	glCreateVertexArrays(1, &VAO);
	glVertexArrayVertexBuffer(VAO, 0, VBO, 0, sizeof(float) * 3);

	glEnableVertexArrayAttrib(VAO, 0);

	glVertexArrayAttribFormat(VAO, 0, 3, GL_FLOAT, GL_FALSE, 0);

	glVertexArrayAttribBinding(VAO, 0, 0);
}

void MyScene::update(float dt)
{
	m_camera->update(dt);
	render();
}

void MyScene::render()
{
	m_myShader->use();
	glBindVertexArray(VAO);
	glDrawArrays(GL_TRIANGLES, 0, 3);
}