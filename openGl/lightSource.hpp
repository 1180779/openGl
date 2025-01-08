
#ifndef U1180779_LIGHT_SOURCE_H
#define U1180779_LIGHT_SOURCE_H

#include <glm/glm.hpp>

#include "cubeShape.hpp"
#include "shader.hpp"
#include "camera.hpp"

class lightSource 
{
public:
    lightSource(const glm::vec3& color = glm::vec3(1.0f, 1.0f, 1.0f));
    lightSource(const lightSource& other);
    ~lightSource();

    void setForShader(shader& sh);

    void render(camera& cam);
    
    inline glm::vec3 color() const { return m_shape.m_color; }
    inline glm::vec3 setColor(const glm::vec3& color) { m_shape.m_color = color; }

    inline glm::vec3 pos() const { return m_shape.m_pos; }
    inline void setPos(glm::vec3 pos) { m_shape.m_pos = pos; }

    float m_specular = 1.0f; /* specular strength */
    float m_diffuse = 1.0f; /* diffuse strength */
    cubeShape m_shape;

    static float s_ambient;

private:
    static int s_count;
    static shader* s_sh;
};

#endif