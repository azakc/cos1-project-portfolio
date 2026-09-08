#ifndef AGENT_H
#define AGENT_H

#include <string>
#include "Weapon.h"

class Agent {
private:
    std::string name;
    std::string role;
    std::string ultimateAbility;
    Weapon* equippedWeapon; // Pointer for dynamic memory / composition management

public:
    Agent(const std::string& agentName, const std::string& agentRole, const std::string& ultName);
    ~Agent(); // Destructor to clean up dynamic memory

    // OOP Encapsulation & Pointer operations
    void EquipWeapon(const Weapon& weaponTemplate);
    void DisplayProfile() const;

    std::string GetName() const;
    std::string GetRole() const;
};

#endif