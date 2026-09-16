#include "Car.h"
#include "Part.h"
#include <iostream>

Car::Car(const std::string& model, int hp)
    : makeModel(model), baseHP(hp) {
}

Car::~Car() {
    for (Part* part : installedParts) {
        delete part;
    }
    installedParts.clear();
}

void Car::InstallPart(Part* newPart) {
    if (newPart != nullptr) {
        installedParts.push_back(newPart);
    }
}

int Car::GetTotalHP() const {
    int totalHP = baseHP;
    for (const Part* part : installedParts) {
        if (part != nullptr) {
            totalHP += part->GetHP();
        }
    }
    return totalHP;
}

size_t Car::GetPartCount() const {
    return installedParts.size();
}

void Car::PrintSpecs() const {
    std::cout << "Vehicle: " << makeModel << "\n";
    std::cout << "Base HP: " << baseHP << " | Total HP: " << GetTotalHP() << "\n";
    std::cout << "Installed Upgrades (" << installedParts.size() << "):\n";

    if (installedParts.empty()) {
        std::cout << "  No performance parts installed.\n";
    }
    else {
        for (size_t i = 0; i < installedParts.size(); ++i) {
            std::cout << "  [" << i + 1 << "] ";
            installedParts[i]->DisplayPart();
        }
    }
}

std::string Car::GetModel() const {
    return makeModel;
}