#ifndef UI_H
#define UI_H

#include <string>
#include <vector>

class Ui {
public:
    void printBanner(const std::string& title) const;
    void printResult(int idx,
                     const std::vector<float>& input,
                     float predicted,
                     float expected) const;
    void printAccuracy(float acc) const;
};

#endif // UI_H
