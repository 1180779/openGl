
#ifndef U1180779_CAMERA_MANAGER_H
#define U1180779_CAMERA_MANAGER_H

#include "camera.hpp"
#include <vector>

class cameraManager 
{
public:

    void prevCamera();
    void nextCamera();
    inline const camera& getCamera() const { return m_cameras[m_curr]; }
    inline camera& getCamera() { return m_cameras[m_curr]; }
    inline int getIndex() { return m_curr; }


    void addCamera(const camera& cam);


private:
    int m_curr = -1; /* current camera index */
    std::vector<camera> m_cameras;
};

#endif