#ifndef GARAGEMANAGER_H
#define GARAGEMANAGER_H

#include <vector>
#include "Car.h"
#include "Part.h"

class GarageManager {
private:
    std::vector<Car*> bays;
    std::vector<Part> shopParts;

public:
    GarageManager();
    ~GarageManager();

    void AddCar(std::string model, int hp);
    void DisplayGarage();
    void DisplayShop();
    void InstallUpgrade(int bayChoice, int partChoice);

    int GetGarageSize();
    int GetShopSize();
};

#endif