#include "ui/ui.h"

#include <iomanip>
#include <iostream>

void Ui::printBanner(const std::string& title) const {
    std::cout << "\n=== " << title << " ===\n";
}

void Ui::printResult(int idx,
                     const std::vector<float>& input,
                     float predicted,
                     float expected) const {
    std::cout << std::fixed << std::setprecision(4)
              << "[" << idx << "]  input=( ";
    for (float v : input)
        std::cout << v << " ";
    std::cout << ")  predicted=" << predicted
              << "  expected=" << expected << "\n";
}

void Ui::printAccuracy(float acc) const {
    std::cout << "Accuracy: " << std::fixed << std::setprecision(1)
              << (acc * 100.0f) << "%\n";
}
