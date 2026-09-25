#include "GarageManager.h"
#include "Car.h"
#include "Part.h"
#include "System.h"
#include <iostream>

GarageManager::GarageManager() {
    // Preset parts inventory catalog
    shopParts = {
        Part("Cold Air Intake", "Intake", 250, 15),
        Part("Performance Exhaust", "Exhaust", 600, 20),
        Part("ECU Stage 1 Tune", "Engine Tuning", 450, 30),
        Part("Turbocharger Kit", "Forced Induction", 1200, 75),
        Part("Supercharger System", "Forced Induction", 2500, 120),
        Part("High-Flow Fuel Injectors", "Fuel System", 350, 25)
    };
}

GarageManager::~GarageManager() {
    for (Car* car : bays) {
        delete car;
    }
    bays.clear();
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
            << shopParts[i].GetName() << " (+"
            << shopParts[i].GetHP() << " HP) - $"
            << shopParts[i].GetCost() << "\n";
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