#include "utils/string_utils.h"

#include <algorithm>
#include <cctype>

namespace StringUtils {

std::string trim(const std::string& s) {
    const auto start = std::find_if_not(s.begin(), s.end(),
        [](unsigned char c){ return std::isspace(c); });
    const auto end   = std::find_if_not(s.rbegin(), s.rend(),
        [](unsigned char c){ return std::isspace(c); }).base();
    return (start < end) ? std::string(start, end) : std::string{};
}

std::string toUpper(std::string s) {
    std::transform(s.begin(), s.end(), s.begin(),
        [](unsigned char c){ return static_cast<char>(std::toupper(c)); });
    return s;
}

} // namespace StringUtils
