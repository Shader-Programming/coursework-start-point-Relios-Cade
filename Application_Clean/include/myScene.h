#pragma once
#include "InputHandler.h"
#include "Scene.h"
#include "Shader.h"
#include "DirectionalLight.h"
#include "Cube.h"
#include "PointLight.h"

class MyScene : public Scene {

public:
    MyScene(GLFWwindow* window, InputHandler* H);
    ~MyScene();
	float f_rotationSpeed;
    void update(float dt) override;

private:

	Shader* m_myShader;
	DirectionalLight* m_directionalLight;
	Cube* m_cube;
	Cube* m_cube2;
	PointLight* m_pointLight;
	PointLight* m_pointLight2;

	//void makeVAO();
	void render();

};


