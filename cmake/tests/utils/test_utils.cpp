#include "dataset_fixture.h"
#include "utils/utils.h"

#include <cmath>
#include <stdexcept>
#include <vector>

TEST_F(DatasetFixture, NormalizeDatasetInputs) {
    // Flatten all inputs from the loaded dataset and normalise them.
    std::vector<float> flat;
    for (const auto& sample : dataset)
        for (float v : sample.first)
            flat.push_back(v);
    const auto norm = Utils::normalize(flat);
    EXPECT_NEAR(norm.front(), 0.0f, 1e-5f);
    EXPECT_NEAR(norm.back(),  1.0f, 1e-5f);
}

TEST_F(DatasetFixture, NormalizeFlatReturnsUnchanged) {
    const auto result = Utils::normalize({3.0f, 3.0f, 3.0f});
    EXPECT_NEAR(result[0], 3.0f, 1e-5f);
}

TEST_F(DatasetFixture, AccuracyPerfectPrediction) {
    // Use dataset expected values as both predicted and expected -> 100%.
    std::vector<float> expected;
    for (const auto& sample : dataset)
        expected.push_back(sample.second[0]);
    EXPECT_FLOAT_EQ(Utils::accuracy(expected, expected), 1.0f);
}

TEST_F(DatasetFixture, AccuracyOneWrong) {
    const float acc = Utils::accuracy({0.9f, 0.9f, 0.9f}, {1.0f, 0.0f, 1.0f});
    EXPECT_LT(acc, 1.0f);
}

TEST_F(DatasetFixture, AccuracySizeMismatchThrows) {
    EXPECT_THROW(Utils::accuracy({0.9f}, {1.0f, 0.0f}), std::invalid_argument);
}

