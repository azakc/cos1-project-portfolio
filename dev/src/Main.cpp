#include <iostream>
#include <string>
#include "GarageManager.h"
#include "System.h"

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
        std::cout << "Choice: ";

        // Basic input check for invalid non-number entries
        if (!(std::cin >> choice)) {
            std::cin.clear();
            std::cin.ignore(1000, '\n');
            std::cout << "\nInvalid input. Enter a number 1-4.\n";
            System::Pause();
            continue;
        }

        if (choice == 1) {
            std::string modelName;
            int horsepower;

            std::cout << "\nEnter car model: ";
            std::cin.ignore(1000, '\n'); // Clear trailing newline from menu selection
            std::getline(std::cin, modelName);

            std::cout << "Enter base horsepower: ";
            std::cin >> horsepower;

            myShop.AddCar(modelName, horsepower);
            System::Pause();
        }
        else if (choice == 2) {
            myShop.DisplayGarage();
            System::Pause();
        }
        else if (choice == 3) {
            if (myShop.GetGarageSize() == 0) {
                std::cout << "\nNo cars available to upgrade!\n";
                System::Pause();
                continue;
            }

            myShop.DisplayGarage();
            std::cout << "\nSelect Bay Number: ";
            int selectedBay;
            std::cin >> selectedBay;

            myShop.DisplayShop();
            std::cout << "\nSelect Part Number: ";
            int selectedPart;
            std::cin >> selectedPart;

            // Pass 1-based choices directly; GarageManager converts them to 0-based indexing
            myShop.InstallUpgrade(selectedBay, selectedPart);
            System::Pause();
        }
        else if (choice == 4) {
            std::cout << "\nExiting shop terminal...\n";
        }
        else {
            std::cout << "\nInvalid choice. Please pick 1 through 4.\n";
            System::Pause();
        }
    }

    return 0;
}