
#include "sceneManager.hpp"

void sceneManager::addObjects()
{
    cameraMan.addCamera(camera());
    camera c;
    c.pos = glm::vec3(10.0f, 10.0f, 10.0f);
    cameraMan.addCamera(c);
    cameraMan.nextCamera();

    glm::vec3 cubePositions[10] = {
        glm::vec3(0.0f,  0.0f,  0.0f),
        glm::vec3(2.0f,  5.0f, -15.0f),
        glm::vec3(-1.5f, -2.2f, -2.5f),
        glm::vec3(-3.8f, -2.0f, -12.3f),
        glm::vec3(2.4f, -0.4f, -3.5f),
        glm::vec3(-1.7f,  3.0f, -7.5f),
        glm::vec3(1.3f, -2.0f, -2.5f),
        glm::vec3(1.5f,  2.0f, -2.5f),
        glm::vec3(1.5f,  0.2f, -1.5f),
        glm::vec3(-1.3f,  1.0f, -1.5f)
    };

    float angle = 50.f;
    for (int i = 0; i < 10; ++i) {
        angle += 50.f;
        objectShape* obj = new cubeShape();
        obj->m_material = material::copper;
        obj->m_pos = cubePositions[i];
        list.addObject(obj);
    }

    lightSpotlight spotlight;
    spotlight.setPos(glm::vec3(0.0f, 0.0f, 3.0f));
    spotlight.m_direction = glm::vec3(0.0f, 0.0f, -1.0f);
    lightMan.addSpotlight(spotlight);

    lightDirectional lightDir;
    lightDir.m_direction = glm::vec3(0.0f, -1.0f, 0.0f);
    lightMan.addDirectionalLight(lightDir);

    lightPoint pointLight;
    pointLight.setPos(glm::vec3(-3.8f, -4.0f, -12.3f));
    lightMan.addPointLight(pointLight);

    pointLight.setPos(glm::vec3(5.0f, 5.0f, 6.0f));
    lightMan.addPointLight(pointLight);
}

void sceneManager::render() const
{
    const camera& cam = cameraMan.getCamera();
    list.render(cam, lightMan);
    lightMan.render(cam);
}
