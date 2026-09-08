#include "Weapon.h"
#include <iostream>

// Constructor setting up the weapon stats
Weapon::Weapon(std::string name, std::string wType, int wCost, int wDmg) {
    weaponName = name;
    type = wType;
    cost = wCost;
    damage = wDmg;
}

std::string Weapon::GetName() const { return weaponName; }
std::string Weapon::GetType() const { return type; }
int Weapon::GetCost() const { return cost; }
int Weapon::GetDamage() const { return damage; }

void Weapon::PrintWeaponInfo() const {
    std::cout << weaponName << " (" << type << ") - Cost: $" << cost << " | Dmg: " << damage << "\n";
}