#include "System.h"
#include "GarageManager.h"
#include <iostream>
#include <cstdlib>
#include <string>

void System::ClearScreen() {
    system("cls");
}

void System::PrintHeader(std::string title) {
    std::cout << "========================================" << std::endl;
    std::cout << " " << title << std::endl;
    std::cout << "========================================" << std::endl;
}

void System::Pause() {
    std::cout << "\nPress Enter to continue...";
    std::cin.ignore(10000, '\n');
    std::cin.get();
}

void HandleInstallUpgrade(GarageManager& manager) {
    // 1. Check if garage has cars and shop has parts
    if (manager.GetGarageSize() == 0) {
        std::cout << "\nNo cars available in service bays to upgrade.\n";
        return;
    }
    if (manager.GetShopSize() == 0) {
        std::cout << "\nNo parts available in shop inventory.\n";
        return;
    }

    // 2. Display available cars and prompt for selection
    std::cout << "\n--- Select Vehicle ---\n";
    manager.DisplayGarage();
    std::cout << "Enter Bay Number (1-" << manager.GetGarageSize() << "): ";
    int bayChoice;
    std::cin >> bayChoice;

    // 3. Display available parts catalog and prompt for selection
    std::cout << "\n--- Select Part to Install ---\n";
    manager.DisplayShop();
    std::cout << "Enter Part Number (1-" << manager.GetShopSize() << "): ";
    int partChoice;
    std::cin >> partChoice;

    // 4. Apply the upgrade directly via GarageManager
    manager.InstallUpgrade(bayChoice, partChoice);
}

void HandleCheckoutCar(GarageManager& manager) {
    if (manager.GetGarageSize() == 0) {
        std::cout << "\nNo cars currently in service bays to checkout.\n";
        return;
    }

    std::cout << "\n--- Checkout Vehicle ---\n";
    manager.DisplayGarage();

    std::cout << "Enter Bay Number to checkout (1-" << manager.GetGarageSize() << "): ";
    int bayChoice;
    if (std::cin >> bayChoice) {
        manager.CheckoutCar(bayChoice);
    }
    else {
        std::cin.clear();
        std::cin.ignore(10000, '\n');
        std::cout << "\nInvalid input.\n";
    }
}