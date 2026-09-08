#ifndef CAR_H
#define CAR_H

#include <string>
#include "Part.h"

// Class representing a vehicle in the garage
class Car {
private:
    std::string makeModel;
    int baseHP;
    Part* installedPart; // Dynamic memory pointer for installed upgrade

public:
    Car(std::string model, int hp);
    ~Car(); // Destructor to clear dynamic memory

    void InstallPart(Part* newPart);
    void PrintSpecs();

    std::string GetModel();
};

#endif