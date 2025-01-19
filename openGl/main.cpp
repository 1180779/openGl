
#include "shader.hpp"
#include "shadersC.hpp"
#include "texture.hpp"
#include "camera.hpp"
#include "objectList.hpp"

#include "lightSource.hpp"
#include "lightDirectional.hpp"
#include "lightPoint.hpp"
#include "lightSpotlight.hpp"

#include "cubeShape.hpp"
#include "lightManager.hpp"

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

#include "application.hpp"

int main(int, char**)
{
    application app;
    app.run();
    return 0;
}
