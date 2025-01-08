#include "lightSource.hpp"

int lightSource::s_count = 0;
shader* lightSource::s_sh = nullptr;

float lightSource::s_ambient = 0.2f;

static const char* lightVertexShaderS = R"(
#version 330 core
layout (location = 0) in vec3 aPos;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

void main()
{
    gl_Position = projection * view * model * vec4(aPos, 1.0);
} 
)";

static const char* lightFragmentShaderS = R"(
#version 330 core
uniform vec3 lightColor;

out vec4 FragColor;

void main()
{
    FragColor = vec4(lightColor, 1.0f); // set transparency to 1.0
}
)";


lightSource::lightSource(const glm::vec3& color) : m_shape(color)
{
    m_shape.m_scale = glm::vec3(0.1f, 0.1f, 0.1f); /* dafault light scale */
    ++s_count;
    if (s_count > 1)
        return;
    
    s_sh = new shader(lightVertexShaderS, lightFragmentShaderS);
}

lightSource::lightSource(const lightSource& other) : m_shape(other.color())
{
    ++s_count;
}

lightSource::~lightSource()
{
    --s_count;
    if (s_count > 0)
        return;

    delete s_sh;
    s_sh = nullptr;
}

void lightSource::setForShader(shader& sh)
{
    glm::vec3 c = color();
    sh.set3f("light.color", c.x, c.y, c.z);

    glm::vec3 p = pos();
    sh.set3f("light.pos", p.x, p.y, p.z);

    sh.set1f("light.ambient", s_ambient);
    sh.set1f("light.specular", m_specular);
    sh.set1f("light.diffuse", m_diffuse);
}

void lightSource::render(camera& cam)
{
    glm::vec3 c = color();

    s_sh->use();
    s_sh->set3f("lightColor", c.x, c.y, c.z);
    cam.use(*s_sh);
    s_sh->setMatrix4fv("model", m_shape.model());
    m_shape.render(*s_sh);
}
