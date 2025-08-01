#include <iostream>
#include <string>
#include <fstream>
#include <ctime>

using namespace std;

class RockPaperScissors {
private:
    string choices[3] = {
        "\n   _______  \n  |       |\n  |       |\n  |  _____|___  \n  | |     | |\n  | |     | |\n  |_|     |_|\n",
        "\n  _______\n |        |\n |        |\n | |      |\n | |      |\n  |_|_____|_\n",
        "\n   _______  \n  |       |\n  |       |\n  |  _____|___  \n  | |    / |\n  | |   /  |\n  |_|  /___|\n"
    };
    string resultMessages[3][3] = {
        {"It's a tie!", "Player 2 wins!", "Player 1 wins!"},
        {"Player 1 wins!", "It's a tie!", "Player 2 wins!"},
        {"Player 2 wins!", "Player 1 wins!", "It's a tie!"}
    };

    int player1Score = 0;
    int player2Score = 0;
    int gameCount = 0;
    int tournamentRounds = 0;

    string player1Name;
    string player2Name;
    string username;
    string password;

    void displayRules() {
        cout << "\n Welcome to Rock, Paper, Scissors Game!\n";
        cout << "\n Rules:\n";
        cout << "1. Rock crushes scissors.\n";
        cout << "2. Scissors cut paper.\n";
        cout << "3. Paper covers rock.\n";
        cout << "\n Choose wisely and may the best player win!\n";
    }

    void displayInstructions() {
        cout << "\nInstructions:\n";
        cout << "1. Choose 'Tournament' , 'Single Match' or 'Computer' mode.\n";
        cout << "2. Enter your moves when prompted.\n";
        cout << "3. Enjoy the game!\n";
    }

    void displayCurrentScore() {
        cout << "\nCurrent Score:\n";
        cout << player1Name << ": " << player1Score << " points\n";
        cout << player2Name << ": " << player2Score << " points\n";
    }

    void getPlayerNames() {
        cout << "\nEnter player names:\n";
        cout << "Player 1: ";
        cin.ignore();
        getline(cin, player1Name);

        if (player1Name == "Computer") {
            player2Name = "Computer";
        } else {
            cout << "Player 2: ";
            getline(cin, player2Name);
        }
    }

    void authenticateUser() {
        cout << "\nAuthentication is required to start the game.\n";
        cout << "Enter your username: ";
        cin >> username;
        cout << "Enter your password: ";
        cin >> password;

        if (username == "Alpha" && password == "*******") {
            cout << "\nAuthentication successful! Starting the game...\n";
        } else {
            cout << "\nAuthentication failed. Access denied.\n";
            exit(1);
        }
    }

    void playWithComputer() {
        int player1Choice;
        int computerChoice;

        cout << "\nDo you want to play against the computer? (y/n): ";
        char choice;
        cin >> choice;

        if (choice == 'y' || choice == 'Y') {
            player2Name = "Computer";
            srand(time(0));

            cout << "\nSingle Match:\n";

            for (gameCount = 0; gameCount < 1; ++gameCount) {
                do {
                    cout << "\n" << player1Name << ", choose your move (0-2):\n";
                    for (int i = 0; i < 3; ++i) {
                        cout << i << " - " << choices[i] << "\n";
                    }
                    cin >> player1Choice;
                } while (player1Choice < 0 || player1Choice > 2);

                computerChoice = rand() % 3;

                cout << "\nYou chose:\n" << choices[player1Choice] << "\n";
                cout << "Computer chose:\n" << choices[computerChoice] << "\n";

                int resultIndex = (player1Choice + computerChoice) % 3;
                cout << resultMessages[player1Choice][resultIndex] << "\n";

                if (resultMessages[player1Choice][resultIndex] == "Player 1 wins!") {
                    player1Score++;
                } else if (resultMessages[player1Choice][resultIndex] == "Player 2 wins!") {
                    player2Score++;
                }

                displayCurrentScore();
            }
        }
    }

    void savePlayerProfile(const string& name, int score) {
        ofstream outfile(name + "_profile.txt");
        if (!outfile) {
            cerr << "Error saving player profile.\n";
            return;
        }
        outfile << "Name: " << name << "\n";
        outfile << "Score: " << score << "\n";
        outfile.close();
        cout << "Player profile saved successfully for " << name << ".\n";
    }

    void loadPlayerProfile(const string& name) {
        ifstream infile(name + "_profile.txt");
        if (!infile) {
            player1Score = 0;
            cout << "No previous profile found for " << name << ". Starting fresh.\n";
        } else {
            string line;
            while (getline(infile, line)) {
                if (line.find("Score:") != string::npos) {
                    player1Score = stoi(line.substr(line.find("Score:") + 7));
                }
            }
            infile.close();
            cout << "Loaded profile for " << name << " with a score of " << player1Score << ".\n";
        }
    }

    void saveTournamentResults() {
        ofstream outfile("tournament_results.txt", std::ios::app);
        if (!outfile) {
            cerr << "Error saving tournament results.\n";
            return;
        }
        outfile << "Tournament Round " << tournamentRounds << ":\n";
        outfile << player1Name << " Score: " << player1Score << "\n";
        outfile << player2Name << " Score: " << player2Score << "\n";
        outfile.close();
        cout << "Tournament results saved successfully.\n";
    }

    void loadTournamentResults() {
        ifstream infile("tournament_results.txt");
        if (!infile) {
            tournamentRounds = 0;
            cout << "No previous tournament results found.\n";
        } else {
            string line;
            while (getline(infile, line)) {
                if (line.find("Tournament Round") != string::npos) {
                    tournamentRounds = stoi(line.substr(17));
                }
            }
            infile.close();
            cout << "Loaded tournament results. Round " << tournamentRounds << " upcoming.\n";
        }
    }

    bool playAgain() {
        char choice;
        cout << "\nDo you want to play again? (y/n): ";
        cin >> choice;
        return (choice == 'y' || choice == 'Y');
    }

    bool resetScores() {
        char choice;
        cout << "\nReset scores? (y/n): ";
        cin >> choice;
        return (choice == 'y' || choice == 'Y');
    }

    bool playTournament() {
        char modeChoice;
        cout << "\nChoose game mode:\n";
        cout << "Tournament (T) or Single Match (S): ";
        cin >> modeChoice;
        return (modeChoice == 'T' || modeChoice == 't');
    }

    bool playSingleMatch() {
        return !playTournament();
    }

    void displayCredits() {
        cout << "\nCredits:\n";
        cout << "This game is made by Data Fardeen, Amina Asghar, Iman Humayun, and Noor Ul Amin.\n";
    }

public:
    void playGame() {
        int player1Choice, player2Choice;

        displayRules();
        displayInstructions();
        getPlayerNames();
        playWithComputer();

        bool isTournament = playTournament();

        if (isTournament) {
            tournamentRounds++;
            for (gameCount = 0; gameCount < 3; ++gameCount) {
                cout << "\nGame " << (gameCount + 1) << ":\n";

                do {
                    cout << "\n" << player1Name << ", choose your move (0-2):\n";
                    for (int i = 0; i < 3; ++i) {
                        cout << i << " - " << choices[i] << "\n";
                    }
                    cin >> player1Choice;
                } while (player1Choice < 0 || player1Choice > 2);

                if (player2Name != "Computer") {
                    do {
                        cout << "\n" << player2Name << ", choose your move (0-2):\n";
                        for (int i = 0; i < 3; ++i) {
                            cout << i << " - " << choices[i] << "\n";
                        }
                        cin >> player2Choice;
                    } while (player2Choice < 0 || player2Choice > 2);
                } else {
                    srand(time(0));
                    player2Choice = rand() % 3;
                }

                cout << "\n" << player1Name << " chose:\n" << choices[player1Choice] << "\n";
                cout << player2Name << " chose:\n" << choices[player2Choice] << "\n";

                int resultIndex = (player1Choice + player2Choice) % 3;
                cout << resultMessages[player1Choice][resultIndex] << "\n";

                if (resultMessages[player1Choice][resultIndex] == "Player 1 wins!") {
                    player1Score++;
                } else if (resultMessages[player1Choice][resultIndex] == "Player 2 wins!") {
                    player2Score++;
                }

                displayCurrentScore();
            }
        } else {
            cout << "\nSingle Match:\n";

            do {
                cout << "\n" << player1Name << ", choose your move (0-2):\n";
                for (int i = 0; i < 3; ++i) {
                    cout << i << " - " << choices[i] << "\n";
                }
                cin >> player1Choice;
            } while (player1Choice < 0 || player1Choice > 2);

            if (player2Name != "Computer") {
                do {
                    cout << "\n" << player2Name << ", choose your move (0-2):\n";
                    for (int i = 0; i < 3; ++i) {
                        cout << i << " - " << choices[i] << "\n";
                    }
                    cin >> player2Choice;
                } while (player2Choice < 0 || player2Choice > 2);
            } else {
                srand(time(0));
                player2Choice = rand() % 3;
            }

            cout << "\n" << player1Name << " chose:\n" << choices[player1Choice] << "\n";
            cout << player2Name << " chose:\n" << choices[player2Choice] << "\n";

            int resultIndex = (player1Choice + player2Choice) % 3;
            cout << resultMessages[player1Choice][resultIndex] << "\n";

            if (resultMessages[player1Choice][resultIndex] == "Player 1 wins!") {
                player1Score++;
            } else if (resultMessages[player1Choice][resultIndex] == "Player 2 wins!") {
                player2Score++;
            }

            displayCurrentScore();
        }
    }

    void displayScores() {
        cout << "\nFinal Scores:\n";
        cout << player1Name << ": " << player1Score << " points\n";
        cout << player2Name << ": " << player2Score << " points\n";
    }

    void startGame() {
        authenticateUser();
        loadPlayerProfile(player1Name);
        loadPlayerProfile(player2Name);
        loadTournamentResults();

        bool isTournament = playTournament();

        do {
            cout << "\nRock, Paper, Scissors Game\n";

            if (isTournament) {
                tournamentRounds++;
            }

            playGame();
            displayScores();

            if (isTournament) {
                player1Score = 0;
                player2Score = 0;
            }

            if (resetScores()) {
                player1Score = 0;
                player2Score = 0;
            }
        } while (playAgain());

        displayCredits();
        cout << "Thanks for playing!\n";
    }
};

int main() {
    RockPaperScissors game;

    cout << "Welcome to the Rock, Paper, Scissors Game!\n";
    game.startGame();

    return 0;
}
