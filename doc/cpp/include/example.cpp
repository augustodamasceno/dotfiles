/*
 * Dot Files - This main C++ file is intended to test 
 * the dot files related to C++.
 *
 * Copyright (c) 2026, Augusto Damasceno.
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-2-Clause
 *
 * See https://github.com/augustodamasceno/dotfiles
 */


#include <string>
#include <iostream>

/**
 * @brief Builds a greeting message for the given name.
 *
 * @param name The name to greet.
 * @return A greeting string in the form "Hello, <name>!".
 */
std::string greet(const std::string& name) {
    return "Hello, " + name + "!";
}

/**
 * @brief Program entry point.
 *
 * Prints a test message and a greeting to standard output.
 *
 * @param argc Number of command-line arguments.
 * @param argv Array of command-line argument strings.
 * @return 0 on success.
 */
int main(int argc, char* argv[]) {
    std::string str = "Testing Dotfiles for C++";
    std::cout << str << std::endl;
    std::cout << greet("World") << std::endl;
    return 0;
}