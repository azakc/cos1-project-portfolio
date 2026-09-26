#ifndef SYSTEM_H
#define SYSTEM_H

#include <string>

class System {
public:
    // Utility functions for terminal formatting
    static void ClearScreen();
    static void Pause();
    static void PrintHeader(const std::string& title);
};

#endif