#include "lightPoint.hpp"

void lightPoint::setForShader(shader& sh) const
{
    lightSource::setForShader(sh);
    sh.set1f("light.constant", m_constant);
    sh.set1f("light.linear", m_linear);
    sh.set1f("light.quadratic", m_quadratic);
}
