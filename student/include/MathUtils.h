#ifndef CPP_FOUNDATIONS_MATHUTILS_H
#define CPP_FOUNDATIONS_MATHUTILS_H

namespace MathUtils {

float Clamp(float x, float minVal, float maxVal);
float Map(float x, float inMin, float inMax, float outMin, float outMax);

} // namespace MathUtils

#endif // CPP_FOUNDATIONS_MATHUTILS_H
