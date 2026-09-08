#ifndef LOADOUTMANAGER_H
#define LOADOUTMANAGER_H

#include <vector>
#include "Agent.h"
#include "Weapon.h"

class LoadoutManager {
private:
    std::vector<Agent*> agentRoster; // Vector holding pointers to dynamic Agent objects
    std::vector<Weapon> buyMenu;     // Vector holding available weapons

public:
    LoadoutManager();
    ~LoadoutManager();

    void AddAgent(const std::string& name, const std::string& role, const std::string& ult);
    void ShowRoster() const;
    void ShowBuyMenu() const;
    void EquipAgentWeapon(int agentIndex, int weaponIndex);

    size_t GetRosterSize() const;
    size_t GetBuyMenuSize() const;
};

#endif