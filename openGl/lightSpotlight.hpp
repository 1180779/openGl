
#ifndef U1180779_LIGHT_SPOTLIGHT_H
#define U1180779_LIGHT_SPOTLIGHT_H

#include "lightSource.hpp"

class lightSpotlight : public lightSource 
{
public:
    lightSpotlight() { }

    glm::vec3 m_direction = glm::normalize(glm::vec3(0.0f, 0.0f, -1.0f));
    float m_cutoff = 12.5f;
    float m_outerCutoff = 25.0f;

    void setForShader(shader& sh) const override;
};

#endif