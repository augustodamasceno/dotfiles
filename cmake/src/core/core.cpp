#include "core/core.h"

std::vector<Core::Sample> Core::xorDataset() const {
    return {
        {{0.0f, 0.0f}, {0.0f}},
        {{0.0f, 1.0f}, {1.0f}},
        {{1.0f, 0.0f}, {1.0f}},
        {{1.0f, 1.0f}, {0.0f}},
    };
}
