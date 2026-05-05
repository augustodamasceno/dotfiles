#include "dataset_fixture.h"
#include "core/math_ops.h"

TEST_F(DatasetFixture, ClampBelowMin) {
    EXPECT_FLOAT_EQ(MathOps::clamp(-1.0f, 0.0f, 1.0f), 0.0f);
}

TEST_F(DatasetFixture, ClampAboveMax) {
    EXPECT_FLOAT_EQ(MathOps::clamp(2.0f, 0.0f, 1.0f), 1.0f);
}

TEST_F(DatasetFixture, ClampWithinRange) {
    EXPECT_FLOAT_EQ(MathOps::clamp(0.5f, 0.0f, 1.0f), 0.5f);
}

TEST_F(DatasetFixture, LerpMidpoint) {
    EXPECT_NEAR(MathOps::lerp(0.0f, 1.0f, 0.5f), 0.5f, 1e-5f);
}

TEST_F(DatasetFixture, ClampDatasetExpectedValues) {
    // All expected outputs in the XOR dataset are already in [0, 1].
    for (const auto& sample : dataset)
        EXPECT_FLOAT_EQ(MathOps::clamp(sample.second[0], 0.0f, 1.0f),
                        sample.second[0]);
}
