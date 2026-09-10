#include "System.h"
#include <iostream>
#include <cstdlib>

void System::ClearScreen() {
    system("cls");
}

void System::PrintHeader(std::string title) {
    std::cout << "========================================" << std::endl;
    std::cout << "  " << title << std::endl;
    std::cout << "========================================" << std::endl;
}

void System::Pause() {
    std::cout << "\nPress Enter to continue...";
    std::cin.ignore(10000, '\n');
    std::cin.get();
}