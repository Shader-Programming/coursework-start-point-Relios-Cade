#pragma once
#include "InputHandler.h"
#include "Scene.h"
#include "Shader.h"

class MyScene : Scene {

public:
    MyScene(GLFWwindow* window, InputHandler* H);
    ~MyScene() {};
    void update(float dt) override;

private:
    Shader* m_myShader;
    unsigned int VBO, VAO, EBO;
	glm::vec3 cubeRota;
	glm::mat4 m_model, m_view, m_projection;

	//std::vector<float> vertexData = {
	//	//  xyz
	//	// back
	//	-0.5f, -0.5f, -0.5f,
	//	 0.5f, -0.5f, -0.5f,
	//	 0.5f,  0.5f, -0.5f,
	//	-0.5f,  0.5f, -0.5f,
	//	// front
	//	-0.5f, -0.5f,  0.5f,
	//	 0.5f, -0.5f,  0.5f,
	//	 0.5f,  0.5f,  0.5f,
	//	-0.5f,  0.5f,  0.5f,
	//	// left
	//	-0.5f,  0.5f,  0.5f,
	//	-0.5f,  0.5f, -0.5f,
	//	-0.5f, -0.5f, -0.5f,
	//	-0.5f, -0.5f,  0.5f,
	//	// right
	//	 0.5f,  0.5f,  0.5f,
	//	 0.5f,  0.5f, -0.5f,
	//	 0.5f, -0.5f, -0.5f,
	//	 0.5f, -0.5f,  0.5f,
	//	 // bottom
	//	 -0.5f, -0.5f, -0.5f,
	//	  0.5f, -0.5f, -0.5f,
	//	  0.5f, -0.5f,  0.5f,
	//	 -0.5f, -0.5f,  0.5f,
	//	 // top
	//	 -0.5f,  0.5f, -0.5f,
	//	  0.5f,  0.5f, -0.5f,
	//	  0.5f,  0.5f,  0.5f,
	//	 -0.5f,  0.5f,  0.5f,
	//};

	std::vector<float> vertexData = {
		//  xyz, normal
		// back
		-0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,
		 0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,
		 0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,
		-0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,
		 //front
		-0.5f, -0.5f,  0.5f,  0.0f,  0.0f,  1.0f,
		 0.5f, -0.5f,  0.5f,  0.0f,  0.0f,  1.0f,
		 0.5f,  0.5f,  0.5f,  0.0f,  0.0f,  1.0f,
		-0.5f,  0.5f,  0.5f,  0.0f,  0.0f,  1.0f,
		 //left
		-0.5f,  0.5f,  0.5f, -1.0f,  0.0f,  0.0f,
		-0.5f,  0.5f, -0.5f, -1.0f,  0.0f,  0.0f,
		-0.5f, -0.5f, -0.5f, -1.0f,  0.0f,  0.0f,
		-0.5f, -0.5f,  0.5f, -1.0f,  0.0f,  0.0f,
		 //right
		 0.5f,  0.5f,  0.5f,  1.0f,  0.0f,  0.0f,
		 0.5f,  0.5f, -0.5f,  1.0f,  0.0f,  0.0f,
		 0.5f, -0.5f, -0.5f,  1.0f,  0.0f,  0.0f,
		 0.5f, -0.5f,  0.5f,  1.0f,  0.0f,  0.0f,
		 // bottom
		 -0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,
		  0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,
		  0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,
		 -0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,
		  //top
		 -0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f,
		  0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f,
		  0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,
		 -0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f
	};

	std::vector<unsigned int> cubeIndices = {
		0, 1, 2, 2, 3, 0,
		4, 5, 6, 6, 7, 4,
		8, 9, 10, 10, 11, 8,
		12, 13, 14, 14, 15, 12,
		16, 17, 18, 18, 19, 16,
		20, 21, 22, 22, 23, 20
	};
    void makeVAO();
    void render();
};

