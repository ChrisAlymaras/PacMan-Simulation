# PacMan-Simulation
This is an academic project for Object-Oriented C++ programming, simulating the classic Pac-Man game. Instead of ghosts, you play as Potter("M") racing against your rival Malphoi("L") to collect the pergamine("#").

**File Overview : 
**
engine.cpp This file builds the game board. It creates the maze from the maze.txt file, which is passed as a command-line argument by the user. It places the players and the pergamine (scroll) on the map and checks who wins.

potter.cpp Represents the player with character 'M', controlled by the user via keyboard input. The goal is to consume the pergamine, which constantly changes position within the map.

malphoi.cpp Represents the player with character 'L', who moves autonomously every time 'M' moves, in a way that chases the pergamine. The goal is also to consume the pergamine, which keeps changing position.

malphoi.h, potter.h, engine.h Contain the class definitions and necessary libraries for their respective .cpp files.

main.cpp Combines all classes and their methods to create the game.

maze.txt, maze2.txt Each file contains a maze where the players will compete.

**Compilation**
g++ engine.cpp potter.cpp malphoi.cpp main.cpp -o main -lncurses

**Run the game**
./main maze.txt
You provide the maze.txt file as an argument, which contains the maze layout.

<img width="503" height="503" alt="image" src="https://github.com/user-attachments/assets/c7cb1f71-8b05-4297-9a54-ab902926b768" />
