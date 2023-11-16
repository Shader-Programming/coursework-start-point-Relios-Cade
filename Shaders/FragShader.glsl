#version 330 core

out vec4 FragColor;
in vec3 normals;
in vec3 posInWS;


//vec3 cubeColour = vec3(0.8824, 0.6784, 0.39);
//vec3 lightColour = vec3(1.0f);
//vec3 lightDirection = vec3(0.05f, -1.0f, 0.0f);


float ambientFactor = 0.5;


float shine = 100.0f;
float specStrength = 0.5f;

uniform vec3 viewPos;

uniform vec3 pointLightPos;
uniform vec3 pointLightColour;
uniform vec3 pointLightAtten;

uniform vec3 lightColour;
uniform vec3 cubeColour;
uniform vec3 lightDirection;

vec3 getDirectionalLight();
vec3 getPointLight();

vec3 n = normalize(normals);
vec3 viewDir = normalize(viewPos - posInWS);

void main()
{
	vec3 result = getDirectionalLight();
	/*result += getPointLight();*/
	FragColor = vec4(result, 1.0);
}

vec3 getPointLight() {
	float distance = length(pointLightPos - posInWS);
	float attn = 1.0 / (pointLightAtten.x + (pointLightAtten.y * distance) + (pointLightAtten.z * (distance * distance)));

	vec3 lightDir = normalize((pointLightPos - posInWS));

	float diffuseFactor = dot(n, lightDir);
	diffuseFactor = max(diffuseFactor, 0.0f);
	vec3 diffuse = cubeColour * pointLightColour * diffuseFactor;

	vec3 H = normalize(lightDir + viewDir);
	float specLevel = dot(n, H);
	specLevel = max(specLevel, 0.0);
	specLevel = pow(specLevel, shine);
	vec3 specular = pointLightColour * specLevel * specStrength;

	diffuse = diffuse * attn;
	specular = specular * attn;
	return specular + diffuse;
}

vec3 getDirectionalLight() {

	vec3 ambient = cubeColour * lightColour * ambientFactor;

	float diffuseFactor = dot(n, -lightDirection);
	diffuseFactor = max(diffuseFactor, 0.0f);
	vec3 diffuse = cubeColour * lightColour * diffuseFactor;

	vec3 H = normalize(-lightDirection + viewDir);
	float specLevel = dot(n, H);
	specLevel = max(specLevel, 0.0);
	specLevel = pow(specLevel, shine);
	vec3 specular = lightColour * specLevel * specStrength;

	return ambient + diffuse + specular;
}

//void main()
//{
//	//FragColor = vec4( 0.5,0.5,0.5, 1.0);
//	//FragColor = vec4(abs(normals), 1.0);
//	vec3 ambient = cubeColour * lightColour * ambientFactor;
////	vec3 result = ambient
////	vec3 result = ambient + diffuse;
//
//	vec3 n = normalize(normals);
//	float diffuseFactor = dot(n, -lightDirection);
//	diffuseFactor = max(diffuseFactor, 0.0f);
//	vec3 diffuse = cubeColour * lightColour * diffuseFactor;
//
//	vec3 viewDir = normalize(viewPos - posInWS);
//	vec3 H = normalize(-lightDirection + viewDir);
//	float specLevel = dot(n, H);
//	specLevel = max(specLevel, 0.0);
//	specLevel = pow(specLevel, shine);
//	vec3 specular = lightColour * specLevel * specStrength;
//
//	vec3 result = ambient + diffuse + specular;
//	FragColor = vec4(result, 1.0);
//}