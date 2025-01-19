
#include "scene.hpp"

void addLights(lightManager& lightMan)
{
    lightSpotlight spotlight;
    spotlight.setPos(glm::vec3(0.0f, 0.0f, 3.0f));
    spotlight.m_direction = glm::vec3(0.0f, 0.0f, -1.0f);
    lightMan.addSpotlight(spotlight);

    lightDirectional lightDir;
    lightDir.m_direction = glm::vec3(0.0f, -1.0f, 0.0f);
    lightMan.addDirectionalLight(lightDir);

    lightPoint pointLight;
    pointLight.setPos(glm::vec3(-5.0f, -5.0f, -15.0f));
    lightMan.addPointLight(pointLight);

    pointLight.setPos(glm::vec3(5.0f, 5.0f, 6.0f));
    lightMan.addPointLight(pointLight);
}
