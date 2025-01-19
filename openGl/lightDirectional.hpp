
#ifndef U1180779_LIGHT_DIRECTIONAL_H
#define U1180779_LIGHT_DIRECTIONAL_H

#include "lightBase.hpp"

class lightDirectional : lightBase 
{
public:
    lightDirectional(glm::vec3 color) : lightBase(color, color, color) { }

    glm::vec3 m_direction = glm::normalize(glm::vec3(1.0f, 1.0f, 0.0f));
    float m_constant = 1.0f;
    float m_linear = 0.09f;
    float m_quadratic = 0.032f;

    void setForShader(shader& sh) const override;
    void render(camera& cam) const override { } /* render is empty */
};

#endif