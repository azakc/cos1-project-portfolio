#include "LoadoutManager.h"
#include <iostream>

LoadoutManager::LoadoutManager() {
    // Pre-populate Weapon Buy Menu
    buyMenu.push_back(Weapon("Classic", "Sidearm", 0, 26));
    buyMenu.push_back(Weapon("Ghost", "Sidearm", 500, 30));
    buyMenu.push_back(Weapon("Spectre", "SMG", 1600, 26));
    buyMenu.push_back(Weapon("Phantom", "Rifle", 2900, 39));
    buyMenu.push_back(Weapon("Vandal", "Rifle", 2900, 40));
    buyMenu.push_back(Weapon("Operator", "Sniper", 4700, 150));
}

LoadoutManager::~LoadoutManager() {
    // Clean up heap allocated Agent pointers stored in vector
    for (Agent* agent : agentRoster) {
        delete agent;
    }
    agentRoster.clear();
}

void LoadoutManager::AddAgent(const std::string& name, const std::string& role, const std::string& ult) {
    // Heap allocation of custom class object
    Agent* newAgent = new Agent(name, role, ult);
    agentRoster.push_back(newAgent);
    std::cout << "\n[+] Added " << name << " (" << role << ") to the active roster!\n";
}

void LoadoutManager::ShowRoster() const {
    if (agentRoster.empty()) {
        std::cout << "\nNo agents unlocked in roster yet.\n";
        return;
    }
    for (size_t i = 0; i < agentRoster.size(); ++i) {
        std::cout << "[" << (i + 1) << "]";
        agentRoster[i]->DisplayProfile();
    }
}

void LoadoutManager::ShowBuyMenu() const {
    std::cout << "\n--- VALORANT BUY MENU ---\n";
    for (size_t i = 0; i < buyMenu.size(); ++i) {
        std::cout << "[" << (i + 1) << "] ";
        buyMenu[i].DisplaySpecs();
    }
}

void LoadoutManager::EquipAgentWeapon(int agentIndex, int weaponIndex) {
    if (agentIndex >= 0 && agentIndex < static_cast<int>(agentRoster.size()) &&
        weaponIndex >= 0 && weaponIndex < static_cast<int>(buyMenu.size())) {

        agentRoster[agentIndex]->EquipWeapon(buyMenu[weaponIndex]);
        std::cout << "\n[!] Equipped " << buyMenu[weaponIndex].GetName()
            << " to " << agentRoster[agentIndex]->GetName() << "!\n";
    }
    else {
        std::cout << "\n[X] Invalid Agent or Weapon selection.\n";
    }
}

size_t LoadoutManager::GetRosterSize() const { return agentRoster.size(); }
size_t LoadoutManager::GetBuyMenuSize() const { return buyMenu.size(); }