#include "PointLight.h"

PointLight::PointLight(glm::vec3 colour, glm::vec3 position, glm::vec3 constant) :
	m_colour(colour),
	m_position(position),
	m_constants(constant)
{}

void PointLight::setLightUniforms(Shader* shader)
{
	shader->use();
	shader->setVec3("pointLightPos", m_position);
	shader->setVec3("pointLightColour", m_colour);
	shader->setVec3("pointAttentuation", m_constants);
}
