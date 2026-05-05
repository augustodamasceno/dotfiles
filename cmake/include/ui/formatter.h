#ifndef FORMATTER_H
#define FORMATTER_H

#include <string>

namespace Formatter {
    std::string floatToString(float value, int precision = 4);
    std::string padLeft(const std::string& s, std::size_t width, char fill = ' ');
}

#endif // FORMATTER_H
