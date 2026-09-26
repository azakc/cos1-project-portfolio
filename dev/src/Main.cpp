#include <iostream>
#include <string>
#include <stdexcept>
#include "GarageManager.h"
#include "System.h"

int GetValidInt(const std::string& prompt) {
    int result = 0;
    while (true) {
        std::cout << prompt;
        std::string input;
        if (!std::getline(std::cin, input)) {
            std::cin.clear();
            continue;
        }

        try {
            size_t processedChars = 0;
            result = std::stoi(input, &processedChars);

            if (processedChars == input.length()) {
                return result;
            }
            std::cout << "Invalid input. Please enter a valid number.\n";
        }
        catch (const std::invalid_argument&) {
            std::cout << "Invalid input. Please enter a valid numeric value.\n";
        }
        catch (const std::out_of_range&) {
            std::cout << "Input out of range. Please enter a smaller number.\n";
        }
    }
}

int main() {
    GarageManager myShop;

    // Default starting cars in the shop
    myShop.AddCar("Nissan GT-R", 565);
    myShop.AddCar("Porsche 911 GT3", 502);

    int choice = 0;

    while (choice != 4) {
        System::ClearScreen();
        System::PrintHeader("PIT CREW & SERVICE SHOP");

        std::cout << "1. Add Car to Service Bay\n";
        std::cout << "2. View Garage Bays & Specs\n";
        std::cout << "3. Install Part Upgrade\n";
        std::cout << "4. Exit\n";

        choice = GetValidInt("Choice: ");

        if (choice == 1) {
            System::ClearScreen();
            System::PrintHeader("ADD CAR TO SERVICE BAY");

            std::string modelName;
            std::cout << "Enter car model: ";
            std::getline(std::cin, modelName);

            int horsepower = GetValidInt("Enter base horsepower: ");

            myShop.AddCar(modelName, horsepower);

            // Return to main menu prompt
            System::Pause();
        }
        else if (choice == 2) {
            System::ClearScreen();
            System::PrintHeader("GARAGE BAYS & SPECS");

            myShop.DisplayGarage();

            // Return to main menu prompt
            System::Pause();
        }
        else if (choice == 3) {
            System::ClearScreen();
            System::PrintHeader("INSTALL PART UPGRADE");

            if (myShop.GetGarageSize() == 0) {
                std::cout << "\nNo cars available to upgrade!\n";
                System::Pause();
                continue;
            }

            myShop.DisplayGarage();
            int selectedBay = GetValidInt("\nSelect Bay Number: ");

            myShop.DisplayShop();
            int selectedPart = GetValidInt("\nSelect Part Number: ");

            myShop.InstallUpgrade(selectedBay, selectedPart);

            // Return to main menu prompt
            System::Pause();
        }
        else if (choice == 4) {
            System::ClearScreen();
            std::cout << "\nExiting shop terminal...\n";
        }
        else {
            std::cout << "\nInvalid choice. Please pick 1 through 4.\n";

            // Pause before clearing on invalid entry
            System::Pause();
        }
    }

    return 0;
}