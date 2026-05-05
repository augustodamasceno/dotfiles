#include "core/math_ops.h"

#include <algorithm>

namespace MathOps {

float clamp(float value, float lo, float hi) {
    return std::max(lo, std::min(value, hi));
}

float lerp(float a, float b, float t) {
    return a + t * (b - a);
}

} // namespace MathOps
