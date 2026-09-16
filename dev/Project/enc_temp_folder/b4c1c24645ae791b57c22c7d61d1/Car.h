#pragma once

#include <string>

// Forward declaration allows storing a Part* pointer without including Part.h here
class Part;

// Class representing a vehicle in the garage
class Car {
private:
    std::string makeModel;
    int baseHP;
    Part* installedPart; // Dynamic memory pointer for installed upgrade

public:
    Car(const std::string& model, int hp);
    ~Car(); // Destructor to clear dynamic memory

    void InstallPart(Part* newPart);
    void PrintSpecs() const;

    std::string GetModel() const;
};