
#ifndef U1180779_SHADERSC_H
#define U1180779_SHADERSC_H

// https://learnopengl.com

// --------------------------------------------------
// basic shaders

const char* vertexSS = R"( 
#version 330 core
layout (location = 0) in vec3 aPos;
layout (location = 1) in vec3 aNormal;

out vec3 P;  
out vec3 normal;  

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

void main()
{
    gl_Position = projection * view * model * vec4(aPos, 1.0);
    P = vec3(model * vec4(aPos, 1.0));
    normal = aNormal;
} 
)";

const char* fragmentSS = R"( 
#version 330 core

struct Material {
    vec3 ambient;
    vec3 diffuse;
    vec3 specular;
    float shininess;
}; 

struct Light {
    vec3 pos;
    vec3 color;
    float ambient;
    float diffuse;
    float specular;
};

out vec4 FragColor;

in vec3 normal;
in vec3 P;
  
uniform Material material;
uniform Light light;

uniform vec3 viewPos;

void main()
{
    vec3 N = normalize(normal);
    vec3 L = normalize(light.pos - P);  
    vec3 V = normalize(viewPos - P);
    vec3 R = reflect(-L, N);

    vec3 ambient = light.ambient * material.ambient; 
    vec3 diffuse = light.diffuse * max(dot(N, L), 0.0) * material.diffuse;
    vec3 specular = light.specular * pow(max(dot(V, R), 0.0), material.shininess) * material.specular;

    vec3 result = ambient + (diffuse + specular) * light.color;

    FragColor = vec4(result, 1.0);
}
)";

#endif