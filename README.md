Rock, Paper, Scissors Game
Description
The Rock, Paper, Scissors Game is an engaging C++ console-based application that brings the classic game to life with single-match and tournament modes, supporting both two-player and player-vs-computer gameplay. Players can choose between Rock, Paper, or Scissors, with intuitive ASCII art representations and clear win/lose/tie outcomes based on traditional rules (Rock crushes Scissors, Scissors cuts Paper, Paper covers Rock). The game includes user authentication, score tracking, and profile saving, enhancing the user experience with persistent data.
Features

Multiple Game Modes: Play a single match or a three-round tournament against another player or the computer.
Interactive Interface: Displays ASCII art for choices and provides clear rules and instructions.
Score Management: Tracks scores across sessions, with options to reset and save profiles to text files.
Player Authentication: Requires a username and password (default: "Alpha"/"*") to start the game.
Computer Opponent: Uses random selection for computer moves in single or tournament modes.
Tournament Tracking: Saves and loads tournament results for continuity.
Play Again Option: Allows replaying without restarting the program.

How to Run

Ensure a C++ compiler (e.g., g++) is installed.
Clone the repository to your local machine.
Compile the code:g++ ROCK_PAPER_SCISSOR.cpp -o rps_game


Run the executable:./rps_game


Enter the username "Alpha" and password "*" to authenticate, then follow the prompts.

Requirements

C++ compiler (e.g., g++, clang++)
Standard libraries: <iostream>, <string>, <fstream>, <ctime>

Usage

Authenticate with the provided credentials.
Choose a game mode (Tournament or Single Match).
Enter player names and select moves (0 for Rock, 1 for Paper, 2 for Scissors).
View results and scores, with options to play again or reset scores.

License
MIT License. See LICENSE for details.
Credits
Developed by Data Fardeen, Amina Asghar, Iman Humayun
