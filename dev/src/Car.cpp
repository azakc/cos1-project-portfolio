#include "Car.h"
#include <iostream>

Car::Car(std::string model, int hp) {
    makeModel = model;
    baseHP = hp;
    installedPart = nullptr; // Starts stock with no aftermarket parts
}

Car::~Car() {
    // Clean up dynamic memory allocation to prevent memory leaks
    if (installedPart != nullptr) {
        delete installedPart;
        installedPart = nullptr;
    }
}

void Car::InstallPart(Part* newPart) {
    // Clear old installed part before adding a new dynamic one
    if (installedPart != nullptr) {
        delete installedPart;
    }

    // Dynamic allocation using heap memory
    installedPart = new Part(newPart->GetName(), newPart->GetCategory(), newPart->GetCost(), newPart->GetHP());
}

void Car::PrintSpecs() {
    int totalHP = baseHP;
    if (installedPart != nullptr) {
        totalHP += installedPart->GetHP();
    }

    std::cout << "\n-----------------------------------\n";
    std::cout << "Vehicle: " << makeModel << "\n";
    std::cout << "Base HP: " << baseHP << " | Total HP: " << totalHP << "\n";
    std::cout << "Installed Upgrade: ";

    if (installedPart != nullptr) {
        installedPart->DisplayPart();
    }
    else {
        std::cout << "Stock / Factory Default\n";
    }
    std::cout << "-----------------------------------\n";
}

std::string Car::GetModel() {
    return makeModel;
}