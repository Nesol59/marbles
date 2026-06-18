#include "task.h"
#include "classes.h"
#include "validator.h"
#include <iostream>
#include <sstream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <windows.h>

void setColor(int color) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, color);
}

void printColorBall(int color) {
    switch (color % 10) {
    case 0: setColor(8); break;
    case 1: setColor(9); break;
    case 2: setColor(10); break;
    case 3: setColor(12); break;
    case 4: setColor(5); break;
    case 5: setColor(6); break;
    case 6: setColor(3); break;
    case 7: setColor(13); break;
    case 8: setColor(11); break;
    case 9: setColor(14); break;
    default: setColor(7); break;
    }
    std::cout << color << " ";
    setColor(7);
}

void printBalls(const std::vector<int>& balls) {
    for (int b : balls) {
        printColorBall(b);
    }
    std::cout << "\n";
}

void taskBalls() {
    std::cout << "\n========================================\n";
    std::cout << "Задача: Шарики\n";
    std::cout << "========================================\n";

    std::srand((unsigned)std::time(nullptr));

    std::cout << "1. Ввести шарики вручную\n";
    std::cout << "2. Сгенерировать случайные шарики\n";
    int choice = InputValidator::getInt("Выберите способ ввода: ", 1, 2);

    std::vector<int> balls;
    int n;

    if (choice == 1) {
        n = InputValidator::getInt("Введите количество шариков (1-100000): ", 1, 100000);
        balls.resize(n);
        for (int i = 0; i < n; i++) {
            int b = InputValidator::getInt("Введите цвет: ", 1, 10);
            balls[i] = b;
        }
        InputValidator::clearInputStream();
        std::cout << "\nВведённая последовательность: ";
        printBalls(balls);
    }
    else {
        n = InputValidator::getInt("Введите количество шариков (1-100000): ", 1, 100000);
        balls.resize(n);
        for (int i = 0; i < n; ++i) {
            balls[i] = rand() % 10;
        }
        std::cout << "\nСгенерированная последовательность: ";
        printBalls(balls);
    }

    BallRemover remover;
    for (int i = 0; i < n; ++i) {
        remover.process(balls[i]);
    }

    std::cout << "\nРезультат: " << remover.getDestroyed(n) << "\n";
}

void showMainMenu() {
    std::cout << "\n========================================\n";
    std::cout << "Динамические структуры данных\n";
    std::cout << "========================================\n";
    std::cout << "1. Задача «Шарики»\n";
    std::cout << "0. Выход\n";
    std::cout << "========================================\n";
}

void runTask(int choice) {
    switch (choice) {
    case 1:
        taskBalls();
        break;
    case 0:
        std::cout << "До свидания!\n";
        break;
    default:
        std::cout << "Неверный выбор!\n";
        break;
    }
}
