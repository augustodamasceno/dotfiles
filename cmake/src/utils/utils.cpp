#include "utils/utils.h"

#include <algorithm>
#include <stdexcept>

std::vector<float> Utils::normalize(std::vector<float> data) {
    const float minVal = *std::min_element(data.begin(), data.end());
    const float maxVal = *std::max_element(data.begin(), data.end());
    const float range  = maxVal - minVal;
    if (range == 0.0f)
        return data;
    for (auto& v : data)
        v = (v - minVal) / range;
    return data;
}

float Utils::accuracy(const std::vector<float>& predicted,
                      const std::vector<float>& expected,
                      float threshold) {
    if (predicted.size() != expected.size())
        throw std::invalid_argument("Size mismatch between predicted and expected");
    int correct = 0;
    for (std::size_t i = 0; i < predicted.size(); ++i)
        if ((predicted[i] >= threshold) == (expected[i] >= threshold))
            ++correct;
    return static_cast<float>(correct) / static_cast<float>(predicted.size());
}
