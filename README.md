# Project & Portfolio 1

### Student First & Last Name

Hello my name is Jamar. I am a student from Full Sail University. The purpose of this repository is to practice development using version control. This work will help me begin to build a portfolio of skills and accomplishment that can be shared in the future.

<br>

## 📢 &nbsp; Weekly Stand Up

Each week I will summarize my milestone activity and progress by writing a stand-up. A stand-up is meant to be a succinct update on how things are going. Use these prompts as a guide on what to write about:

⚙️ Overview - What I worked on this past week
<br>
🌵 Challenges - What problems did I have & how I'm addressing them
<br>
🏆 Accomplishments - What is something I "leveled up" on this week
<br>
🔮 Next Steps - What I plan to prioritize and do next

<br>

### Week 1

⚙️ Overview - What I worked on this past week

Initialized version control using Git and GitHub Classroom for my C++ project.

Created structured technical documentation using Markdown syntax, setting up a comprehensive project README.md.

Set up the foundation for my project codebase, organizing source files, header files, and build assets.

🌵 Challenges - What problems did I have & how I'm addressing them

Challenge: Ensuring proper repository structure and managing Git remote links accurately during initial setup.

Resolution: Reviewed Git workflow commands (git status, git commit, git push) and utilized branching/pull requests to track changes cleanly.

🏆 Accomplishments - What is something I "leveled up" on this week

Mastered writing clean Markdown syntax to format technical documentation, including code blocks, key specs, and project layout.

Established a solid, reproducible version control habit early in the development lifecycle.

🔮 Next Steps - What I plan to prioritize and do next

Build out core C++ class architecture and method definitions.

Implement memory management and core data handling routines.

Continue making atomic Git commits as new functionality is implemented.

### Week 2

### Week 2 Standup Update

⚙️ **Overview - What I worked on this past week**

* Implemented core C++ project architecture across custom header files (`Car.h`, `GarageManager.h`, `Part.h`, `System.h`) and corresponding source files.
* Built out utility functions in `System.cpp` for console interface management, including UI header formatting (`PrintHeader`), screen clearing (`ClearScreen`), and input pausing (`Pause`).
* Connected main project logic and module definitions within Visual Studio, maintaining organized separation between declarations and implementations.

🌵 **Challenges - What problems did I have & how I'm addressing them**

* **Challenge:** Handling console input stream buffering and ensuring reliable cross-platform screen clearing/pausing without leftover newline artifacts breaking input flow.
* **Resolution:** Standardized input stream flushing using `std::cin.ignore()` alongside `std::cin.get()` to cleanly manage user transitions.

🏆 **Accomplishments - What is something I "leveled up" on this week**

* Advanced my understanding of standard class separation and modular program structure in C++.
* Streamlined terminal UI workflows and input handling strategies within complex console-based applications.

🔮 **Next Steps - What I plan to prioritize and do next**

* Flesh out core data structures and logic inside `GarageManager.cpp`, `Car.cpp`, and `Part.cpp`.
* Implement state management and main menu loops in `Main.cpp` to tie all system utility helper methods together.
* Continue pushing structured, atomic commits to track modular feature implementations cleanly.

### Week 3

⚙️ **Overview - What I worked on this past week**

* Implemented the core execution loop and interactive menu navigation in `Main.cpp` using `System` console utilities.
* Built out search member functions (`FindCarById` and `FindCarsByModel`) in `GarageManager.cpp` to filter vehicle inventory.
* Resolved build configuration breaks in Visual Studio and updated local Git tracking against remote feature branches.

🛠️ **Improvements - What changes, refinements, or refactoring did I complete this week**

* Standardized input stream buffer clearing across menu selections using `std::cin.ignore()` and `std::cin.clear()` to prevent input skip bugs.
* Cleaned up project file metadata (`.vcxproj` and `.vcxproj.filters`) by removing duplicate header dependencies causing load failures.

🌵 **Challenges - What problems did I have & how I'm addressing them**

* **Challenge:** Visual Studio failing to load the project file due to duplicate XML filter entries (`System.h`) and running Git commands outside the repo root directory.
* **Resolution:** Manually edited `Project.vcxproj` to strip duplicate `<ClInclude>` declarations and verified active PowerShell paths before executing version control commands.

🏆 **Accomplishments - What is something I "leveled up" on this week**

* Gained direct experience manually repairing broken C++ project configuration files and managing branch merges in Git.
* Improved menu state control flow and input validation techniques in C++ console applications.

🔮 **Next Steps - What I plan to prioritize and do next**

* Test edge cases across interactive menu inputs and service bay vehicle search routines.
* Finalize documentation and issue references before submitting Week 4 pull requests.

### Week 4

⚙️ **Overview - What I worked on this past week**

* Standardized screen navigation using custom header banners (`System::PrintHeader`).
* Added `ClearScreen` calls between menu transitions and wired up an exit confirmation sequence to ensure a smooth console UX.

🌵 **Challenges - What problems did I have & how I'm addressing them**

* **Challenge:** Managing raw pointers and dynamic vector safety across garage bays and shop inventory.
* **Resolution:** Enforced strict 0-based boundary checks and added explicit destructor cleanup to eliminate memory leaks.

🏆 **Accomplishments - What is something I "leveled up" on this week**

* Mastered object-oriented pointer management alongside robust input validation, ensuring CLI terminal stability when handling invalid user input.

🔮 **Next Steps & Future Development**

* Implement file I/O operations to persist garage state across application sessions.
* Build out dynamic inventory sorting algorithms for shop parts.
