#ifndef WEAPON_H
#define WEAPON_H

#include <string>

class Weapon {
private:
    std::string weaponName;
    std::string type;
    int cost;
    int damage;

public:
    Weapon(std::string name, std::string wType, int wCost, int wDmg);

    // Getters for weapon info
    std::string GetName() const;
    std::string GetType() const;
    int GetCost() const;
    int GetDamage() const;

    void PrintWeaponInfo() const;
};

#endif