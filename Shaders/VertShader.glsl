#version 330 core

layout(location = 0) in vec3 aPos;
layout(location = 1) in vec3 aNormals;

out vec3 normals;
out vec3 posInWS;

uniform mat4 Model;
uniform mat4 View;
uniform mat4 Projection;


void main()
{
	//vertexColour = aCol;
	vec4 worldSpace = Model * vec4(aPos, 1.0);
	posInWS = worldSpace.xyz;
	gl_Position = Projection * View * Model * vec4(aPos, 1.0);
	normals = mat3(transpose(inverse(Model))) * aNormals;
}