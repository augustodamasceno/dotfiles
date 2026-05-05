#pragma once

#include "core/core.h"

#include <gtest/gtest.h>

#include <fstream>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>

class DatasetFixture : public ::testing::Test {
protected:
    // Loaded once per test suite; available to every TEST_F in the suite.
    inline static std::vector<Core::Sample> dataset;

    static void SetUpTestSuite() {
        const std::string path =
            std::string(TEST_RESOURCES_DIR) + "/xor_dataset.csv";

        std::ifstream file(path);
        if (!file.is_open())
            throw std::runtime_error("Cannot open resource: " + path);

        std::string line;
        while (std::getline(file, line)) {
            if (line.empty() || line[0] == '#')
                continue;
            std::istringstream ss(line);
            float in1{}, in2{}, expected{};
            char  comma{};
            ss >> in1 >> comma >> in2 >> comma >> expected;
            dataset.push_back({{in1, in2}, {expected}});
        }
    }

    static void TearDownTestSuite() {
        dataset.clear();
    }
};
