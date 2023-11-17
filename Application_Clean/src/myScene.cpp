#include "myScene.h"
#include "cube.h"
#include "Plane.h"

MyScene::MyScene(GLFWwindow* window, InputHandler* H) : Scene(window, H)
{
	m_camera = new FirstPersonCamera();
	m_camera->attachHandler(m_window, m_handler);
	m_myShader = new Shader("..\\Shaders\\VertShader.glsl", "..\\Shaders\\FragShader.glsl");

	m_directionalLight = new DirectionalLight(glm::vec3(1.0, 1.0, 1.0), glm::vec3(0.25f, -1.0f, 0.5f), 0.2f);
	m_directionalLight->setLightUniforms(m_myShader);

	m_cube = new Cube(glm::vec3(0.8824, 0.6784, 0.39), 64, 16); //cube 1 colour
	m_cube->setCubeMaterialValues(m_myShader);

	m_cube2 = new Cube(glm::vec3(0.8824, 0.6784, 0.39), 64, 16); //cube 2 colour
	m_cube2->transform(glm::vec3(5.0, 0.0, 0.0)); //cube's potion from cube 1
	m_cube2->setCubeMaterialValues(m_myShader);

	m_pointLight = new PointLight(glm::vec3(1.0, 0.0, 0.0), glm::vec3(-2.0, 0.0, 3.0), glm::vec3(1.0, 0.22, 0.02));
	m_pointLight->setLightUniforms(m_myShader);

	m_pointLight2 = new PointLight(glm::vec3(0.0, 0.0, 1.0), glm::vec3(2.0, 0.0, 0.0), glm::vec3(1.0, 0.22, 0.02));
	m_pointLight2->setLightUniforms(m_myShader);

	m_plane = new Plane(glm::vec3(0.8824, 0.6784, 0.39), 64, 16);
	m_plane->setPlaneMaterialValues(m_myShader);

	f_rotationSpeed = 0.015;
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
	// Clear the screen and depth buffer
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	// Set up view and projection matrices
	m_myShader->use();
	m_myShader->setMat4("View", m_camera->getViewMatrix());
	m_myShader->setMat4("Projection", m_camera->getProjectionMatrix());
	m_myShader->setVec3("viewPos", m_camera->getPosition());

	// Render the cubes
	glBindVertexArray(m_cube->getVAO());

	m_cube->setTransform(m_myShader);
	m_cube->rotate(f_rotationSpeed, glm::vec3(1.0, 0.0, 0.0));
	glDrawElements(GL_TRIANGLES, m_cube->getIndicesCount(), GL_UNSIGNED_INT, 0);

	m_cube2->setTransform(m_myShader);
	m_cube2->rotate(-f_rotationSpeed, glm::vec3(0.0, 1.0, 0.0));
	glDrawElements(GL_TRIANGLES, m_cube2->getIndicesCount(), GL_UNSIGNED_INT, 0);

	// Render the plane
	glBindVertexArray(m_plane->getVAO());

	m_plane->setTransform(m_myShader);
	glDrawElements(GL_TRIANGLES, m_plane->getIndicesCount(), GL_UNSIGNED_INT, 0);
}




