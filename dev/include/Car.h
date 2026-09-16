#pragma once

#include <string>
#include <vector>

// Forward declaration allows storing Part* pointers without including Part.h here
class Part;

// Class representing a vehicle in the garage
class Car {
private:
    std::string makeModel;
    int baseHP;
    std::vector<Part*> installedParts; // Dynamic collection of installed upgrades

public:
    Car(const std::string& model, int hp);
    ~Car(); // Destructor cleans up allocated dynamic memory for all installed parts

    void InstallPart(Part* newPart);
    void PrintSpecs() const;

    int GetTotalHP() const;
    size_t GetPartCount() const;
    std::string GetModel() const;
};