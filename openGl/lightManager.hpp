
#ifndef U1180779_LIGHT_MANAGER_H
#define U1180779_LIGHT_MANAGER_H

#include "lightDirectional.hpp"
#include "lightPoint.hpp"
#include "lightSpotlight.hpp"

#include "camera.hpp"
#include <vector>

class lightManager 
{
public:
    void addPointLight(const lightPoint& light);
    void addSpotlight(const lightSpotlight& light);
    void addDirectionalLight(const lightDirectional& light);

    void setForShader(shader& sh) const;
    void render(camera& cam);

    std::vector<lightPoint> m_pointLights;
    std::vector<lightSpotlight> m_spotlights;
    std::vector<lightDirectional> m_directionalLights;
};

#endif