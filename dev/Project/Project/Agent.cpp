#include "Agent.h"
#include <iostream>

Agent::Agent(const std::string& agentName, const std::string& agentRole, const std::string& ultName)
    : name(agentName), role(agentRole), ultimateAbility(ultName), equippedWeapon(nullptr) {
}

Agent::~Agent() {
    // Dynamic memory cleanup
    if (equippedWeapon != nullptr) {
        delete equippedWeapon;
        equippedWeapon = nullptr;
    }
}

void Agent::EquipWeapon(const Weapon& weaponTemplate) {
    // Clear previously allocated memory if equipping a new weapon
    if (equippedWeapon != nullptr) {
        delete equippedWeapon;
    }
    // Dynamic allocation using heap memory
    equippedWeapon = new Weapon(weaponTemplate);
}

void Agent::DisplayProfile() const {
    std::cout << "\n========================================\n";
    std::cout << " Agent: " << name << " | Role: " << role << "\n";
    std::cout << " Ultimate: " << ultimateAbility << "\n";
    std::cout << " Equipped Weapon: ";
    if (equippedWeapon != nullptr) {
        equippedWeapon->DisplaySpecs();
    }
    else {
        std::cout << "None (Sidearm only)\n";
    }
    std::cout << "========================================\n";
}

std::string Agent::GetName() const { return name; }
std::string Agent::GetRole() const { return role; }