#pragma once

#include <vector>
#include <string>
#include "Part.h"

class Car;

class GarageManager {
private:
    std::vector<Car*> bays;
    std::vector<Part> shopParts;
    static constexpr size_t MAX_BAYS = 5; // Set desired capacity cap
    std::vector<Car*> bays;
    std::vector<Part> shopParts;

public:
    GarageManager();
    ~GarageManager();

    // Core Garage Functionality
    void AddCar(const std::string& model, int hp);
    void DisplayGarage() const;
    void DisplayShop() const;
    void InstallUpgrade(int bayChoice, int partChoice);

    int GetGarageSize() const;
    int GetShopSize() const;

    // Search Routines
    Car* FindCarById(int id) const;
    std::vector<Car*> FindCarsByModel(const std::string& modelQuery) const;

    bool IsGarageFull() const;
};