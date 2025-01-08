
#include "objectShape.hpp"

const glm::mat4 objectShape::s_model = glm::mat4(1.0f);

/* unified shader names */

const char* objectShape::s_colorShaderName = "objectColor";

/* methods */

void objectShape::render(shader& sh) const
{
    sh.use();
    sh.set3f("material.ambient", m_material.ambient);
    sh.set3f("material.diffuse", m_material.diffuse);
    sh.set3f("material.specular", m_material.specular);
    sh.set1f("material.shininess", m_material.shininess);
}

glm::mat4 objectShape::model() const
{
    auto t = s_model;
    t = glm::rotate(t, glm::radians(m_pitch), glm::vec3(1.0f, 0.0f, 0.0f));
    t = glm::rotate(t, glm::radians(m_yaw), glm::vec3(0.0f, 1.0f, 0.0f));
    t = glm::rotate(t, glm::radians(m_roll), glm::vec3(0.0f, 0.0f, 1.0f));
    t = glm::translate(t, m_pos);
    t = glm::scale(t, m_scale);
    return t;
}

glm::mat4 objectShape::normalMatrix() const
{
    auto t = s_model;
    t = glm::scale(t, m_scale);
    return glm::transpose(glm::inverse(t));
}

