/*
 * Dot Files - This test file is intended to test 
 * the dot files related to C++.
 *
 * Copyright (c) 2026, Augusto Damasceno.
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-2-Clause
 *
 * See https://github.com/augustodamasceno/dotfiles
 */

#include <gtest/gtest.h>
#include <string>


TEST(DotfilesTest, StringNotEmpty) {
    std::string str = "Testing Dotfiles for C++";
    EXPECT_FALSE(str.empty());
}

TEST(DotfilesTest, StringContent) {
    std::string str = "Testing Dotfiles for C++";
    EXPECT_EQ(str, "Testing Dotfiles for C++");
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
