#include "GarageManager.h"
#include "Car.h" 
#include <iostream>

GarageManager::GarageManager() {
}

GarageManager::~GarageManager() {
    for (Car* car : bays) {
        delete car;
    }
    bays.clear();
}

void GarageManager::AddCar(const std::string& model, int hp) {
    bays.push_back(new Car(model, hp));
}

void GarageManager::DisplayGarage() const {
    if (bays.empty()) {
        std::cout << "No vehicles currently in service bays.\n";
        return;
    }

    for (size_t i = 0; i < bays.size(); ++i) {
        std::cout << "Bay [" << i + 1 << "]:\n";
        bays[i]->PrintSpecs();
        std::cout << "-----------------------\n";
    }
}

void GarageManager::DisplayShop() const {
    if (shopParts.empty()) {
        std::cout << "No shop parts available.\n";
        return;
    }

    for (size_t i = 0; i < shopParts.size(); ++i) {
        std::cout << "[" << i + 1 << "] ";
        shopParts[i].DisplayPart();
    }
}

void GarageManager::InstallUpgrade(int bayChoice, int partChoice) {
    int bayIndex = bayChoice - 1;
    int partIndex = partChoice - 1;

    if (bayIndex < 0 || bayIndex >= static_cast<int>(bays.size())) {
        std::cout << "Invalid bay selection.\n";
        return;
    }

    if (partIndex < 0 || partIndex >= static_cast<int>(shopParts.size())) {
        std::cout << "Invalid part selection.\n";
        return;
    }

    // Allocate a heap copy of the selected part and install it
    Part* newPart = new Part(shopParts[partIndex]);
    bays[bayIndex]->InstallPart(newPart);
    std::cout << "Part successfully installed!\n";
}

int GarageManager::GetGarageSize() const {
    return static_cast<int>(bays.size());
}

int GarageManager::GetShopSize() const {
    return static_cast<int>(shopParts.size());
}