#include "dataset_fixture.h"
#include "ui/formatter.h"

TEST_F(DatasetFixture, FloatToStringPrecision) {
    EXPECT_EQ(Formatter::floatToString(3.14159f, 2), "3.14");
}

TEST_F(DatasetFixture, FloatToStringZero) {
    EXPECT_EQ(Formatter::floatToString(0.0f, 1), "0.0");
}

TEST_F(DatasetFixture, PadLeftPadsCorrectly) {
    EXPECT_EQ(Formatter::padLeft("42", 5), "   42");
}

TEST_F(DatasetFixture, PadLeftNoOpWhenLong) {
    EXPECT_EQ(Formatter::padLeft("hello", 3), "hello");
}

TEST_F(DatasetFixture, FormatDatasetExpectedValues) {
    // Every formatted expected value should be non-empty.
    for (const auto& sample : dataset)
        EXPECT_FALSE(Formatter::floatToString(sample.second[0]).empty());
}
