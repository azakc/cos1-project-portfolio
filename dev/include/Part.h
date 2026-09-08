#ifndef PART_H
#define PART_H

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
    Part(std::string name, std::string cat, int pCost, int hp);

    // Getters
    std::string GetName();
    std::string GetCategory();
    int GetCost();
    int GetHP();

    void DisplayPart();
};

#endif