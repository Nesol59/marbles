#include "validator.h"

void InputValidator::clearInputStream() {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

int InputValidator::getInt(const std::string& prompt, int min, int max) {
    int value;
    while (true) {
        std::cout << prompt;
        std::cin >> value;
        if (std::cin.fail()) {
            std::cout << "Ошибка: введите целое число!\n";
            clearInputStream();
        }
        else if (value < min || value > max) {
            std::cout << "Ошибка: число должно быть от " << min << " до " << max << "\n";
            clearInputStream();
        }
        else {
            clearInputStream();
            return value;
        }
    }
}