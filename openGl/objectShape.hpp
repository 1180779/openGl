
#ifndef U1180779_OBJECT_H
#define U1180779_OBJECT_H

#include <glad/glad.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include "shader.hpp"
#include "material.hpp"

class objectShape
{
public:
    objectShape() { }
    objectShape(const objectShape& other)
        : m_pos(other.m_pos), m_scale(other.m_scale),
        m_pitch(other.m_pitch), m_yaw(other.m_yaw), m_roll(other.m_roll),
        m_material(other.m_material) { }

    virtual void render(shader& sh) const;

    glm::mat4 model() const; /* model matrix */
    glm::mat4 normalMatrix() const; /* matrix for normal vectors */

    /* position variables */

    glm::vec3 m_pos = glm::vec3(0.0f, 0.0f, 0.0f);
    glm::vec3 m_scale = glm::vec3(1.0f, 1.0f, 1.0f);
    float m_pitch = 0.0f;
    float m_yaw = 0.0f;
    float m_roll = 0.0f;

    material m_material = material::copper;

protected:
    static const char* s_colorShaderName;

private:
    static const glm::mat4 s_model;
};

#endif