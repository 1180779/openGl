#include "objectList.hpp"
#include <glm/gtc/matrix_transform.hpp>

objectList::~objectList()
{
    for (auto o : m_objs) {
        delete o;
    }
}

void objectList::addObject(object* obj, const glm::vec3& location)
{
    m_objs.push_back(obj);
    m_locations.push_back(location);
}

void objectList::render(shader& sh, std::string name)
{
    for (int i = 0; i < m_objs.size(); ++i) {
        sh.setMatrix4fv(name, glm::translate(
            glm::rotate(m_objs[i]->model(), glm::radians(m_angle), m_v), m_locations[i]));
        m_objs[i]->render();
    }
}

void objectList::rotate(float angle, const glm::vec3& v)
{
    m_angle = angle;
    m_v = glm::normalize(v);
}
