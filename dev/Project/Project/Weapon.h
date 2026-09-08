#ifndef WEAPON_H
#define WEAPON_H

#include <string>

class Weapon {
private:
    std::string name;
    std::string category;
    int cost;
    int baseDamage;

public:
    Weapon(const std::string& weaponName, const std::string& weaponCategory, int weaponCost, int damage);

    // Getters
    std::string GetName() const;
    std::string GetCategory() const;
    int GetCost() const;
    int GetBaseDamage() const;

    void DisplaySpecs() const;
};

#endif