#ifndef VALIDATOR_H
#define VALIDATOR_H

#include <iostream>
#include <string>
#include <limits>

class InputValidator {
public:
    static void clearInputStream();
    static int getInt(const std::string& prompt, int min = INT_MIN, int max = INT_MAX);
};

#endif