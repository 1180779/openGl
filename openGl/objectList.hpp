
#ifndef U1180779_OBJECTLIST_H
#define U1180779_OBJECTLIST_H

#include "shader.hpp"
#include "objectShape.hpp"
#include <glm/glm.hpp>
#include <vector>
#include <string>

#include "camera.hpp"
#include "lightBase.hpp"

class objectList 
{
public:
    objectList(shader& sh);
    ~objectList();

    objectList& addObject(objectShape* obj);

    void reset() { m_trans = glm::mat4(1.0f); }
    virtual objectList& translate(const glm::vec3& v);
    virtual objectList& rotate(const float angle, const glm::vec3& v);
    virtual objectList& scale(const glm::vec3& v);

    void render(camera& cam, lightBase& light, std::string name = "model");

    shader& m_sh;
    std::vector<objectShape*> m_objs;
    glm::mat4 m_trans = glm::mat4(1.0f);
};

#endif