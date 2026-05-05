#ifndef UTILS_H
#define UTILS_H

#include <vector>

class Utils {
public:
    static std::vector<float> normalize(std::vector<float> data);
    static float accuracy(const std::vector<float>& predicted,
                          const std::vector<float>& expected,
                          float threshold = 0.5f);
};

#endif // UTILS_H
