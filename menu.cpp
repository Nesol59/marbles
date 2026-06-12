#include "menu.h"
#include "task.h"
#include "validator.h"

void run() {
    int choice;
    do {
        showMainMenu();
        choice = InputValidator::getInt("Выберите пункт: ", 0, 1);
        runTask(choice);
        if (choice != 0) {
            std::cout << "\nНажмите Enter для продолжения...";
            std::cin.get();
        }
    } while (choice != 0);
}