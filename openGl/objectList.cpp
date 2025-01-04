#include "objectList.hpp"

objectList::~objectList()
{
    for (auto o : m_objs) {
        delete o;
    }
}

void objectList::addObject(object* obj, const glm::mat4& model)
{
    m_objs.push_back(obj);
    m_models.push_back(model);
}

void objectList::render()
{
    for (auto o : m_objs) {
        o->render();
    }
}
