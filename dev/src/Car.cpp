#include "Car.h"
#include "Part.h" // Full definition included here for method calls and dynamic memory access
#include <iostream>

Car::Car(const std::string& model, int hp)
    : makeModel(model), baseHP(hp), installedPart(nullptr) {
}

Car::~Car() {
    delete installedPart;
    installedPart = nullptr;
}

void Car::InstallPart(Part* newPart) {
    if (installedPart != nullptr) {
        delete installedPart; // Clean up old memory before reassigning
    }
    installedPart = newPart;
}

void Car::PrintSpecs() const {
    std::cout << "Vehicle: " << makeModel << "\n";
    std::cout << "Base HP: " << baseHP << "\n";
    if (installedPart != nullptr) {
        std::cout << "Installed Upgrade:\n  ";
        installedPart->DisplayPart();
    }
    else {
        std::cout << "No performance part installed.\n";
    }
}

std::string Car::GetModel() const {
    return makeModel;
}