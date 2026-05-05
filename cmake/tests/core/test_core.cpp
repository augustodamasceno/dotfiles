#include "dataset_fixture.h"

#include <vector>

TEST_F(DatasetFixture, XorDatasetSize) {
    EXPECT_EQ(dataset.size(), 4u);
}

TEST_F(DatasetFixture, XorDatasetValues) {
    EXPECT_EQ(dataset[0].first,  (std::vector<float>{0.0f, 0.0f}));
    EXPECT_EQ(dataset[0].second, (std::vector<float>{0.0f}));

    EXPECT_EQ(dataset[1].first,  (std::vector<float>{0.0f, 1.0f}));
    EXPECT_EQ(dataset[1].second, (std::vector<float>{1.0f}));

    EXPECT_EQ(dataset[2].first,  (std::vector<float>{1.0f, 0.0f}));
    EXPECT_EQ(dataset[2].second, (std::vector<float>{1.0f}));

    EXPECT_EQ(dataset[3].first,  (std::vector<float>{1.0f, 1.0f}));
    EXPECT_EQ(dataset[3].second, (std::vector<float>{0.0f}));
}

