#pragma once
#include "InputHandler.h"
#include "Scene.h"
#include "Shader.h"
#include "Lights/DirectionalLight.h"
#include "Cube.h"

class MyScene : Scene {

public:
    MyScene(GLFWwindow* window, InputHandler* H);
    ~MyScene();
    void update(float dt) override;

private:

	Shader* m_myShader;
	DirectionalLight* m_directionalLight;
	Cube* m_cube;
	//Cube* m_cube2;
	//PointLight* m_pointLight;
	//PointLight* m_pointLight1;

	//void makeVAO();
	void render();

};


