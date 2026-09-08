#include "Weapon.h"
#include <iostream>

Weapon::Weapon(const std::string& weaponName, const std::string& weaponCategory, int weaponCost, int damage)
    : name(weaponName), category(weaponCategory), cost(weaponCost), baseDamage(damage) {
}

std::string Weapon::GetName() const { return name; }
std::string Weapon::GetCategory() const { return category; }
int Weapon::GetCost() const { return cost; }
int Weapon::GetBaseDamage() const { return baseDamage; }

void Weapon::DisplaySpecs() const {
    std::cout << "  - " << name << " [" << category << "] | Cost: " << cost << " Creds | Damage: " << baseDamage << "\n";
}