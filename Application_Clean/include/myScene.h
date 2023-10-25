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
    unsigned int VBO, VAO;
    float vertexData[9] = {
        0.5,0.5,0.0,
        -0.5,0.5,0.0,
        -0.5,-0.5,0.0,
    };
    void makeVAO();
    void render();
};

