

#ifndef U1180779_SCENE_MANAGER_H
#define U1180779_SCENE_MANAGER_H

#include "shader.hpp"
#include "shadersC.hpp"
#include "objectList.hpp"
#include "camera.hpp"
#include "lightManager.hpp"

class sceneManager 
{
public:
    void addObjects();
    void render() const;

    shader sh = shader(vertexSS, fragmentSSCombined);
    objectList list = objectList(sh);
    camera cam;
    lightManager lightMan;
};

#endif