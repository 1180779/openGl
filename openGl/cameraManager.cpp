
#include "cameraManager.hpp"

void cameraManager::prevCamera()
{
    --m_curr;
    if (m_curr < 0)
        m_curr = m_cameras.size() - 1;
    getCamera().setCurrent();
}

void cameraManager::nextCamera()
{
    ++m_curr;
    if (m_curr >= m_cameras.size())
        m_curr = 0;
    getCamera().setCurrent();
}

void cameraManager::addCamera(const camera& cam)
{
    m_cameras.push_back(cam);
}
