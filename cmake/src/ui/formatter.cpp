#include "ui/formatter.h"

#include <iomanip>
#include <sstream>
#include <algorithm>

namespace Formatter {

std::string floatToString(float value, int precision) {
    std::ostringstream oss;
    oss << std::fixed << std::setprecision(precision) << value;
    return oss.str();
}

std::string padLeft(const std::string& s, std::size_t width, char fill) {
    if (s.size() >= width)
        return s;
    return std::string(width - s.size(), fill) + s;
}

} // namespace Formatter
