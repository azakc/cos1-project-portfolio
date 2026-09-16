#include "Part.h"
#include <iostream>

Part::Part()
    : partName(""), category(""), cost(0), horsepowerGain(0) {
}

Part::Part(const std::string& name, const std::string& cat, int pCost, int hp)
    : partName(name), category(cat), cost(pCost), horsepowerGain(hp) {
}

std::string Part::GetName() const {
    return partName;
}

std::string Part::GetCategory() const {
    return category;
}

int Part::GetCost() const {
    return cost;
}

int Part::GetHP() const {
    return horsepowerGain;
}

void Part::DisplayPart() const {
    std::cout << "Part: " << partName
        << " | Category: " << category
        << " | Cost: $" << cost
        << " | HP Gain: +" << horsepowerGain << " HP\n";
}