#include "lightDirectional.hpp"

void lightDirectional::setForShader(shader& sh) const
{
    lightBase::setForShader(sh);
    sh.set3f("light.direction", -m_direction);
}

