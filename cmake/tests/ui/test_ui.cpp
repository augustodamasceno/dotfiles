#include "dataset_fixture.h"
#include "ui/ui.h"

#include <iostream>
#include <sstream>

TEST_F(DatasetFixture, PrintBannerProducesOutput) {
    std::ostringstream buf;
    std::streambuf* old = std::cout.rdbuf(buf.rdbuf());
    Ui ui;
    ui.printBanner("Test Banner");
    std::cout.rdbuf(old);
    EXPECT_FALSE(buf.str().empty());
}

TEST_F(DatasetFixture, PrintResultFromDataset) {
    std::ostringstream buf;
    std::streambuf* old = std::cout.rdbuf(buf.rdbuf());
    Ui ui;
    for (std::size_t i = 0; i < dataset.size(); ++i)
        ui.printResult(static_cast<int>(i),
                       dataset[i].first,
                       dataset[i].second[0],
                       dataset[i].second[0]);
    std::cout.rdbuf(old);
    EXPECT_FALSE(buf.str().empty());
}

TEST_F(DatasetFixture, PrintAccuracyContainsPercent) {
    std::ostringstream buf;
    std::streambuf* old = std::cout.rdbuf(buf.rdbuf());
    Ui ui;
    ui.printAccuracy(1.0f);
    std::cout.rdbuf(old);
    EXPECT_NE(buf.str().find('%'), std::string::npos);
}

