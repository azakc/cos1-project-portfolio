#include "GarageManager.h"
#include <iostream>

GarageManager::GarageManager() {
    // shop items available for install
    Part p1("ECU Tune", "Software", 600, 40);
    Part p2("High Flow Injectors", "Fuel", 450, 20);
    Part p3("Supercharger", "Engine", 5000, 150);

    shopParts.push_back(p1);
    shopParts.push_back(p2);
    shopParts.push_back(p3);
}

GarageManager::~GarageManager() {
    // delete all dynamically allocated cars in the vector
    for (int i = 0; i < bays.size(); i++) {
        delete bays[i];
    }
}

void GarageManager::AddCar(std::string model, int hp) {
    Car* temp = new Car(model, hp);
    bays.push_back(temp);
    std::cout << "\nAdded car to Bay " << bays.size() << "!\n";
}

void GarageManager::DisplayGarage() {
    if (bays.size() == 0) {
        std::cout << "\nNo cars in service bays.\n";
        return;
    }

    for (int i = 0; i < bays.size(); i++) {
        std::cout << "\nBay " << (i + 1) << ":";
        bays[i]->PrintSpecs();
    }
}

void GarageManager::DisplayShop() {
    std::cout << "\nShop Parts:\n";
    for (int i = 0; i < shopParts.size(); i++) {
        std::cout << (i + 1) << ". ";
        shopParts[i].DisplayPart();
    }
}

void GarageManager::InstallUpgrade(int bayChoice, int partChoice) {
    // check bay choice
    if (bayChoice < 0 || bayChoice >= bays.size()) {
        std::cout << "\nInvalid bay number.\n";
        return;
    }

    // check part choice
    if (partChoice < 0 || partChoice >= shopParts.size()) {
        std::cout << "\nInvalid part number.\n";
        return;
    }

    // apply the upgrade
    bays[bayChoice]->InstallPart(&shopParts[partChoice]);
    std::cout << "\nPart successfully added!\n";
}

int GarageManager::GetGarageSize() {
    return bays.size();
}

int GarageManager::GetShopSize() {
    return shopParts.size();
}