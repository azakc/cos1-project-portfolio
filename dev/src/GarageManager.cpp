#include "GarageManager.h"
#include "Car.h"
#include "Part.h"
#include "System.h"
#include <iostream>

GarageManager::GarageManager() {
    shopParts.push_back(new Part("Cold Air Intake", "Intake", 250, 15));
    shopParts.push_back(new Part("Performance Exhaust", "Exhaust", 600, 20));
    shopParts.push_back(new Part("ECU Stage 1 Tune", "Engine Tuning", 450, 30));
    shopParts.push_back(new Part("Turbocharger Kit", "Forced Induction", 1200, 75));
    shopParts.push_back(new Part("Supercharger System", "Forced Induction", 2500, 120));
    shopParts.push_back(new Part("High-Flow Fuel Injectors", "Fuel System", 350, 25));
}

GarageManager::~GarageManager() {
    for (Car* car : bays) {
        delete car;
    }
    bays.clear();

    for (Part* part : shopParts) {
        delete part;
    }
    shopParts.clear();
}

void GarageManager::AddCar(const std::string& model, int hp) {
    if (bays.size() >= MAX_BAYS) {
        std::cout << "Garage Full! Cannot add another car.\n";
        return;
    }

    bays.push_back(new Car(model, hp));
}

void GarageManager::DisplayGarage() const {
    System::PrintHeader("CURRENT GARAGE BAYS");

    if (bays.empty()) {
        std::cout << "No vehicles currently in service bays.\n";
        return;
    }

    for (size_t i = 0; i < bays.size(); ++i) {
        std::cout << "Bay [" << i + 1 << "]:\n";
        bays[i]->PrintSpecs();
        std::cout << "----------------------------------------\n";
    }
}

void GarageManager::DisplayShop() const {
    System::PrintHeader("PARTS & UPGRADES SHOP");

    if (shopParts.empty()) {
        std::cout << "No shop parts available.\n";
        return;
    }

    for (size_t i = 0; i < shopParts.size(); ++i) {
        std::cout << "Part [" << i + 1 << "]: "
            << shopParts[i]->GetName() << " (+"
            << shopParts[i]->GetHP() << " HP) - $"
            << shopParts[i]->GetCost() << "\n";
    }
}

bool GarageManager::CheckoutCar(int bayIndex) {
    int index = bayIndex - 1;

    if (index < 0 || index >= static_cast<int>(bays.size())) {
        std::cout << "\nInvalid bay number.\n";
        return false;
    }

    std::cout << "\nCar checked out from Bay " << bayIndex << ".\n";

    delete bays[index];
    bays.erase(bays.begin() + index);

    return true;
}

void GarageManager::InstallUpgrade(int bayIndex, int partIndex) {
    int carIdx = bayIndex - 1;
    int partIdx = partIndex - 1;

    if (carIdx < 0 || carIdx >= static_cast<int>(bays.size())) {
        std::cout << "\nInvalid bay choice.\n";
        return;
    }

    if (partIdx < 0 || partIdx >= static_cast<int>(shopParts.size())) {
        std::cout << "\nInvalid part choice.\n";
        return;
    }

    Car* selectedCar = bays[carIdx];
    Part* selectedPart = shopParts[partIdx];

    selectedCar->InstallPart(selectedPart);

    std::cout << "\nSuccessfully installed " << selectedPart->GetName()
        << " on " << selectedCar->GetModel() << "!\n";
    std::cout << "New Total Horsepower: " << selectedCar->GetTotalHP() << " HP\n";
}

int GarageManager::GetGarageSize() const {
    return static_cast<int>(bays.size());
}

int GarageManager::GetShopSize() const {
    return static_cast<int>(shopParts.size());
}