
#ifndef U1180779_OBJECTLIST_H
#define U1180779_OBJECTLIST_H

#include "object.hpp"
#include <glm/glm.hpp>
#include <vector>

class objectList 
{
public:
    ~objectList();
    void addObject(object* obj, const glm::mat4& model);
    void render();

    std::vector<object*> m_objs;
    std::vector<glm::mat4> m_models;
};

#endif