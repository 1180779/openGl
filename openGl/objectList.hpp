
#ifndef U1180779_OBJECTLIST_H
#define U1180779_OBJECTLIST_H

#include "shader.hpp"
#include "object.hpp"
#include <glm/glm.hpp>
#include <vector>
#include <string>

class objectList 
{
public:
    ~objectList();
    void addObject(object* obj, const glm::vec3& location);
    void render(shader& sh, std::string name = "model");
    void rotate(float angle, const glm::vec3& v = glm::vec3(1.f, 0.f, 0.f));

    float m_angle = 0.f;
    glm::vec3 m_v = glm::vec3(1.f, 0.f, 0.f);

    std::vector<object*> m_objs;
    std::vector<glm::vec3> m_locations;
};

#endif