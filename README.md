# TUTORIAL

## 1) Git installation

**Git Terminal(Ubuntu)**
- $ sudo apt-get install git-all

**Git Terminal(Debian)**
- $ sudo dnf install git-all
 
**Git Terminal(Windows 32Bit)**
- https://github.com/git-for-windows/git/releases/download/v2.13.2.windows.1/Git-2.13.2-32-bit.exe

**Git Terminal(Windows 64Bit)**- https://github.com/git-for-windows/git/releases/download/v2.13.2.windows.1/Git-2.13.2-64-bit.exe
 
 
 
## 2) Git cloning (first time only)

**Git Cloning Terminal**
- git clone https://github.com/Heist1/Heist1
 
 
 
## 3) Git Pull (to sincronize github folder)

**Git Pull**
- Change the current working directory to your local repository.
- git pull               //Update the current repository, downloads new files.
 
 
 
## 4) For Collaborators only
 
**GitHub Collaborator Account**
- email:heist1@munoubengoshi.gq
- username:Heist1
- password:Heist12345

**Login**
- git config --global user.email heist1@munoubengoshi.gq
- git config --global user.name Heist1

**Uploading a file**
- Change the current working directory to your local repository(C:\Users\Username\Heist1>).
- git pull
- git Fetch
- git add prova.cpp         //git add . (instead of add prova.cpp) for all the files in the directory.
- git commit -m "prova"
- git push origin master
