#include "pointLight.h"

PointLight::PointLight(glm::vec3 colour, glm::vec3 position, glm::vec3 constant) :
	m_colour(colour),
	m_position(position),
	m_constants(constant)
{}

void PointLight::setLightUniforms(Shader* shader)
{
	shader->use();
	shader->setVec3("pLightPosition", m_position);
	shader->setVec3("pLightColour", m_colour);
	shader->setVec3("pAttentuation", m_constants);
}