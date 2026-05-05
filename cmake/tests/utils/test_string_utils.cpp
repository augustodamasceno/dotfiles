#include "dataset_fixture.h"
#include "utils/string_utils.h"

TEST_F(DatasetFixture, TrimLeadingAndTrailing) {
    EXPECT_EQ(StringUtils::trim("  hello  "), "hello");
}

TEST_F(DatasetFixture, TrimEmptyString) {
    EXPECT_EQ(StringUtils::trim("   "), "");
}

TEST_F(DatasetFixture, ToUpperConverts) {
    EXPECT_EQ(StringUtils::toUpper("xor"), "XOR");
}

TEST_F(DatasetFixture, ToUpperAlreadyUpper) {
    EXPECT_EQ(StringUtils::toUpper("XOR"), "XOR");
}

TEST_F(DatasetFixture, TrimDatasetSize) {
    // Sanity: dataset should have been loaded (resource file is readable).
    EXPECT_EQ(StringUtils::trim("  4  "), "4");
    EXPECT_EQ(dataset.size(), 4u);
}
