#include "myScene.h"
#include "cube.h"

MyScene::MyScene(GLFWwindow* window, InputHandler* H) : Scene(window, H)
{
	m_camera = new FirstPersonCamera();
	m_camera->attachHandler(m_window, m_handler);
	m_myShader = new Shader("..\\Shaders\\vertexShader.glsl", "..\\Shaders\\fragmentShader.glsl");

	m_directionalLight = new DirectionalLight(glm::vec3(1.0), glm::vec3(0.25f, -1.0f, 0.5f));
	m_directionalLight->setLightUniforms(m_myShader);

	m_cube = new Cube(glm::vec3(0.5, 0.5, 0.5), 64, 16);
	m_cube->setCubeMaterialValues(m_myShader);

	m_cube2 = new Cube(glm::vec3(0.5, 0.5, 0.5), 64, 16);
	m_cube2->transform(glm::vec3(5.0, 0.0, 0.0));
	m_cube2->setCubeMaterialValues(m_myShader);

	m_pointLight = new PointLight(glm::vec3(1.0, 0.0, 0.0), glm::vec3(-2.0, 0.0, 3.0), glm::vec3(1.0, 0.22, 0.02));
	m_pointLight->setLightUniforms(m_myShader);

	m_pointLight2 = new PointLight(glm::vec3(0.0, 0.0, 1.0), glm::vec3(2.0, 0.0, 0.0), glm::vec3(1.0, 0.22, 0.02));
	m_pointLight2->setLightUniforms(m_myShader);

	f_rotationSpeed = 0.01;
}

MyScene::~MyScene()
{
	delete m_myShader;
	delete m_cube;
	delete m_cube2;
	delete m_directionalLight;
}

void MyScene::update(float dt)
{
	m_camera->update(dt);
	render();
}

void MyScene::render()
{

	m_myShader->setMat4("View", m_camera->getViewMatrix());
	m_myShader->setMat4("Projection", m_camera->getProjectionMatrix());
	m_myShader->setVec3("viewPos", m_camera->getPosition());

	glBindVertexArray(m_cube->getVAO());

	m_cube->setTransform(m_myShader);
	m_cube->rotate(f_rotationSpeed, glm::vec3(1.0, 1.0, 0.0));
	glDrawElements(GL_TRIANGLES, m_cube->getIndicesCount(), GL_UNSIGNED_INT, 0);

	m_cube2->setTransform(m_myShader);
	m_cube2->rotate(-f_rotationSpeed, glm::vec3(1.0, 1.0, 0.0));
	glDrawElements(GL_TRIANGLES, m_cube->getIndicesCount(), GL_UNSIGNED_INT, 0);
}


