#pragma once

#include <vector>
#include <string>
#include "Part.h" 

// Forward declaration avoids heavy header coupling since bays stores pointers (Car*)
class Car;

class GarageManager {
private:
    std::vector<Car*> bays;
    std::vector<Part> shopParts;

public:
    GarageManager();
    ~GarageManager();

    void AddCar(const std::string& model, int hp);
    void DisplayGarage() const;
    void DisplayShop() const;
    void InstallUpgrade(int bayChoice, int partChoice);

    int GetGarageSize() const;
    int GetShopSize() const;
};