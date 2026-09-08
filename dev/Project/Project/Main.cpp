#include <iostream>
#include <string>
#include <limits>
#include "LoadoutManager.h"

void DisplayMenu() {
    std::cout << "\n========== VALORANT TAC-GEAR MANAGER ==========\n";
    std::cout << "1. Recruit New Agent\n";
    std::cout << "2. View Agent Roster & Loadouts\n";
    std::cout << "3. Purchase/Equip Weapon from Buy Menu\n";
    std::cout << "4. Exit Program\n";
    std::cout << "Select an option (1-4): ";
}

int main() {
    LoadoutManager manager;

    // Default starter agents
    manager.AddAgent("Jett", "Duelist", "Blade Storm");
    manager.AddAgent("Sova", "Initiator", "Hunter's Fury");

    int choice = 0;
    while (choice != 4) {
        DisplayMenu();
        if (!(std::cin >> choice)) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "\nInvalid input. Please enter a number.\n";
            continue;
        }

        switch (choice) {
        case 1: {
            std::string name, role, ult;
            std::cout << "\nEnter Agent Name: ";
            std::cin >> name;
            std::cout << "Enter Agent Role (Duelist/Initiator/Controller/Sentinel): ";
            std::cin >> role;
            std::cout << "Enter Ultimate Ability Name: ";
            std::cin.ignore();
            std::getline(std::cin, ult);

            manager.AddAgent(name, role, ult);
            break;
        }
        case 2:
            manager.ShowRoster();
            break;

        case 3: {
            if (manager.GetRosterSize() == 0) {
                std::cout << "\nRecruit an agent first!\n";
                break;
            }

            manager.ShowRoster();
            std::cout << "Select Agent Number to equip: ";
            int agentChoice;
            std::cin >> agentChoice;

            manager.ShowBuyMenu();
            std::cout << "Select Weapon Number to buy: ";
            int weaponChoice;
            std::cin >> weaponChoice;

            manager.EquipAgentWeapon(agentChoice - 1, weaponChoice - 1);
            break;
        }
        case 4:
            std::cout << "\nExiting Valorant Tac-Gear Manager. Good luck on the field!\n";
            break;

        default:
            std::cout << "\nInvalid option selected. Try again.\n";
            break;
        }
    }

    return 0;
}