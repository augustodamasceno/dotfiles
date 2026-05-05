#ifndef CORE_H
#define CORE_H

#include <vector>
#include <utility>

class Core {
public:
    using Vec    = std::vector<float>;
    using Sample = std::pair<Vec, Vec>;

    std::vector<Sample> xorDataset() const;
};

#endif // CORE_H
