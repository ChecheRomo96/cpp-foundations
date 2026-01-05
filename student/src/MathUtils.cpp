#include "MathUtils.h"

namespace MathUtils {

float Clamp(float x, float minVal, float maxVal) {
    if (x < minVal) return minVal;
    if (x > maxVal) return maxVal;
    return x;
}

float Map(float x, float inMin, float inMax, float outMin, float outMax) {
    const float denom = (inMax - inMin);
    // For now, assume denom != 0. Handling denom == 0 can be added as a later exercise.
    const float t = (x - inMin) / denom;
    return outMin + t * (outMax - outMin);
}

} // namespace MathUtils
