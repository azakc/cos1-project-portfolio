# Instructions

Update this document where indicated [look for the brackets!]. Replace text inside the brackets with your own information. For example: Course Name should be the name of this course, and not the generic words "Course Name".

<br>

## [ Project And Portfolio I: Computer Science - Online]

- **[ Jamar Maye ]**
- **[ 9/6/2026 ]**

This paper addresses some of the topic matter covered in research and activity this week. Be sure to include reference links below to the research and information you used to complete this assignment.

## Topic: Terminal

Professional developers use Terminal daily. It's essential to understand some fundamental commands to use the application.

Update the information below to demonstrate your knowledge on this topic.

**1. Using Terminal, there are essential commands to know.**

List the correct Terminal commands to do the actions listed below. Replace **CMD** with the correct command sequence. You can keep or enhance the brief description.

**The last bullet provides an example**.

- [ clear]: Clear the Screen
- [ pwd]: Print the "Working Directory"
- [ ls]: List files and folders
- [ ls -a]: List files and folders, including invisible files
- [ ls -lh]: List all files and folders, in human readable form
- [ cd]: Change directory
- [ cd /]: Change directory, go to root directory
- [ cd ~]: Change directory and go to user home directory
- [ cd ..]: Change directory, go up one folder level
- [ cd ../..]: Change directory, go up two folder levels
- [ cd ~/Desktop]: Change directory to my desktop!

**2. Using Terminal...**

**Folder Drop:** Try typing "cd" followed by a space, and then drag a folder into terminal and press return. Test this out and describe your results below.

[ The `cd` (Change Directory) command successfully changed the current working directory from `C:\Users\chord` to `C:\Users\chord\OneDrive\Videos\Clipchamp` ]

## Topic: Version Control & Git

Version control, also known as revision control, records changes to a file or set of files over time so that you can recall specific versions later. In this class, we are learning Git. Update the information below where indicated.

**1. There are three types of version control.**

[ Local Version Control Systems - Keeps Track of file changes using a simple database right on your own machine. 2. Central Version Control (CVCS) - Relies on a single central server to hold all project files and history. Devs check files out from that server and push changes back to it. The main drawback though is if the server is down, no one can save versions or collaborate until it's back up.  3. Distributed Version Control (DVCS)- Gives every team member a full clone of the entire repos and it's full history locally. You can commit and work completely offline, and if the main remote host crashes, any devs local repo can be used to restore it. ]
**2. Using Terminal, there are also essential Git commands to know.**

List the correct Git commands to do the actions listed below in Terminal. Replace CMD with the correct command and keep or enhance the brief description.

- [ git clone <repo-url ]: Clone a repository
- [ git config --global user.name "Your Name" ]: Set-up a global user name
- [ git config --global user.email "your-email@example.com"]: Set-up a global email address (to match my GitHub account email)
- [ git status ]: Shows the current state of your directory and staging area
- [ git add .]: Add modified files to the next commit
- [ git commit -m "Your commit message"]: Make a commit with a new message
- [ git log ]: Show my commit history
- [ git help ]: Show Git's help screen

**3. Connecting to GitHub using Terminal.**
HTTPS is the the correct way to connect to GitHub in this course. Describe how you connect to GitHub from Terminal using this protocol. What steps do you take?

[ - Copy the repository's HTTPS URL from GitHub (e.g., `[https://github.com/username/repository.git](https://github.com/username/repository.git)`).
    
- Open Terminal, navigate to the folder where you want to store the project, and run `git clone <HTTPS-URL>`.
    
- If connecting an existing local repository instead, link it by running `git remote add origin <HTTPS-URL>`.
    
- When pushing changes via `git push -u origin main`, authenticate using your GitHub username and a Personal Access Token (PAT) instead of a standard account password.]

**4. Using .gitignore and Why it's Important**  
Most repositories contain a .gitignore file.

- What is the purpose of this file?
  <br>
  [A `.gitignore` file tells Git which files or directories to ignore so they aren't tracked or committed to the repository.]

- What is the "**.DS_Store**" file and why would you want to ignore it?
  <br>
  [It's a hidden macOS system file that saves folder layout preferences (icon positions, window size). It has nothing to do with code, so ignoring it keeps the repo clean and avoids unnecessary commits.]

- What other file or folder would you want to add to a .gitignore file and why?
  <br>
  [- **Build folders & binaries (`.vs/`, `x64/`, `build/`, `*.exe`):** IDE-generated settings and compiled binaries. They take up space and can easily be rebuilt locally.
    
- **`.env` files:** Store sensitive data like API keys and passwords. Ignoring them stops credentials from leaking to GitHub.]

<br>

# Reference Links

Replace the example references below with your own links and recommended resources. It is acceptable to provide multiple links for a single topic and to use material provided to you in this class. You are encouraged to link to your own independent research as well.

[ Research Summary: What resource(s) did you find most helpful this past week and why? ]

**Terminal Commands**  
[Site Address](https://www.someaddress.com/full/url/)

**Three Types of Version Control**  
[Site Address](https://www.someaddress.com/full/url/)

**Git Commands**  
[Site Address](https://www.someaddress.com/full/url/)

**Connecting to GitHub using Terminal**  
[Site Address](https://www.someaddress.com/full/url/)

**Using .gitignore and Why it's Important**  
[Site Address](https://www.someaddress.com/full/url/)
