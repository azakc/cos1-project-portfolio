#include "Part.h"
#include <iostream>

Part::Part() {
    partName = "Stock";
    category = "Factory";
    cost = 0;
    horsepowerGain = 0;
}

Part::Part(std::string name, std::string cat, int pCost, int hp) {
    partName = name;
    category = cat;
    cost = pCost;
    horsepowerGain = hp;
}

std::string Part::GetName() { return partName; }
std::string Part::GetCategory() { return category; }
int Part::GetCost() { return cost; }
int Part::GetHP() { return horsepowerGain; }

void Part::DisplayPart() {
    std::cout << partName << " [" << category << "] - $" << cost << " (+ " << horsepowerGain << " HP)\n";
}