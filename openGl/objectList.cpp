
#include <glm/gtc/matrix_transform.hpp>
#include "objectList.hpp"

objectList::objectList(shader& sh) : m_sh(sh) { }

objectList::~objectList()
{
    for (auto o : m_objs) {
        delete o;
    }
}

objectList& objectList::addObject(objectShape* obj)
{
    m_objs.push_back(obj);
    return *this;
}

objectList& objectList::translate(const glm::vec3& v)
{
    m_trans = glm::translate(m_trans, v);
    return *this;
}

objectList& objectList::rotate(const float angle, const glm::vec3& v)
{
    m_trans = glm::rotate(m_trans, glm::radians(angle), glm::normalize(v));
    return *this;
}

objectList& objectList::scale(const glm::vec3& v)
{
    m_trans = glm::scale(m_trans, v);
    return *this;
}

void objectList::render(camera& cam, lightBase& light, std::string modelName)
{
    cam.use(m_sh);
    light.setForShader(m_sh, "light");
    for (int i = 0; i < m_objs.size(); ++i) {
        m_sh.setMatrix4fv(modelName, m_trans * m_objs[i]->model());
        m_objs[i]->render(m_sh);
    }
}
