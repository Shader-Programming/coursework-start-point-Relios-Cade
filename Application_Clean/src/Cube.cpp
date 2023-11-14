#include "cube.h"

Cube::Cube(glm::vec3 colour, float shine, float specStrength) :
	m_colour(colour),
	m_specStrength(specStrength),
	m_shine(shine)
{
	makeVAO();
	resetTransform();
}

Cube::~Cube() {

}

void Cube::setCubeMaterialValues(Shader* shader)
{
	shader->use();
	shader->setVec3("cubeColour", m_colour);
	shader->setFloat("shine", m_shine);
	shader->setFloat("specStrength", m_specStrength);
}

void Cube::rotate(float angle, glm::vec3 axis)
{
	m_transform = glm::rotate(m_transform, (float)(angle), axis);
}

void Cube::scale(float scaleFactor, glm::vec3 axis)
{
}

void Cube::transform(glm::vec3 translation)
{
	m_transform = glm::translate(m_transform, translation);
}

void Cube::makeVAO()
{
	glCreateBuffers(1, &m_VBO);
	glNamedBufferStorage(m_VBO, sizeof(float) * vertexData.size(), vertexData.data(), GL_DYNAMIC_STORAGE_BIT);

	glCreateBuffers(1, &m_EBO);
	glNamedBufferStorage(m_EBO, sizeof(unsigned int) * cubeIndices.size(), cubeIndices.data(), GL_DYNAMIC_STORAGE_BIT);

	glCreateVertexArrays(1, &m_VAO);
	glVertexArrayVertexBuffer(m_VAO, 0, m_VBO, 0, sizeof(float) * 6);
	glVertexArrayElementBuffer(m_VAO, m_EBO);

	glEnableVertexArrayAttrib(m_VAO, 0);
	glEnableVertexArrayAttrib(m_VAO, 1);

	glVertexArrayAttribFormat(m_VAO, 0, 3, GL_FLOAT, GL_FALSE, 0);
	glVertexArrayAttribFormat(m_VAO, 1, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float));

	glVertexArrayAttribBinding(m_VAO, 0, 0);
	glVertexArrayAttribBinding(m_VAO, 1, 0);
}
