#pragma once

#include <string>

// Class to handle performance upgrades
class Part {
private:
    std::string partName;
    std::string category;
    int cost;
    int horsepowerGain;

public:
    Part();
    Part(const std::string& name, const std::string& cat, int pCost, int hp);

    // Getters
    std::string GetName() const;
    std::string GetCategory() const;
    int GetCost() const;
    int GetHP() const;

    void DisplayPart() const;
};