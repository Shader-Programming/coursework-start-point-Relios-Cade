#pragma once
#include "Shader.h"
#include "DirectionalLight.h"

class PointLight {
public:
	PointLight(glm::vec3 colour, glm::vec3 position, glm::vec3 constant);
	~PointLight() {};

	void setLightUniforms(Shader* shader);

	void setConstants(glm::vec3& constants) { m_constants = constants; }
	void setPosition(glm::vec3& pos) { m_position = pos; }

	glm::vec3& getPosition() { return m_position; }
	glm::vec3& getConstants() { return m_constants; }

protected:
	glm::vec3 m_colour;
	glm::vec3 m_constants;
	glm::vec3 m_position;
};