
#include "lightSpotlight.hpp"

void lightSpotlight::setForShader(shader& sh) const
{
    lightSource::setForShader(sh);
    sh.set3f("light.direction", -m_direction);
    sh.set1f("light.cutoff", glm::cos(glm::radians(m_cutoff)));
    sh.set1f("light.outerCutoff", glm::cos(glm::radians(m_outerCutoff)));
}
