#include <iostream>
using namespace std;

char boardARR[9];

void resetBoard() {
    for (int i = 0; i < 9; i++) {
        boardARR[i] = ' ';
    }
}

void displayBoard() {
    cout << " " << boardARR[0] << " | " << boardARR[1] << " | " << boardARR[2] << " " << endl;
    cout << "---|---|---" << endl;
    cout << " " << boardARR[3] << " | " << boardARR[4] << " | " << boardARR[5] << " " << endl;
    cout << "---|---|---" << endl;
    cout << " " << boardARR[6] << " | " << boardARR[7] << " | " << boardARR[8] << " " << endl;
}

bool checkwin(char p) {
    // Check rows
    for (int i = 0; i < 9; i += 3) {
        if (boardARR[i] == p && boardARR[i + 1] == p && boardARR[i + 2] == p) {
            return true;
        }
    }
    // Check columns
    for (int i = 0; i < 3; i++) {
        if (boardARR[i] == p && boardARR[i + 3] == p && boardARR[i + 6] == p) {
            return true;
        }
    }
    // Check diagonals
    if (boardARR[0] == p && boardARR[4] == p && boardARR[8] == p) {
        return true;
    }
    if (boardARR[2] == p && boardARR[4] == p && boardARR[6] == p) {
        return true;
    }
    return false;
}

bool checkdraw() {
    for (int i = 0; i < 9; i++) 
        if (boardARR[i] != 'X'&& boardARR[i] !='0') 
            return false;
    return true;
}

int main() {
    char player, playAgian;
    do {
        resetBoard();
        player = 'X';
        while (true) {
            displayBoard();
            int move;
            cout << "Player " << player << ", enter your move (1-9): ";
            cin >> move;
            move--; // Adjust for 0-based index

            if (move < 0 || move >= 9 || boardARR[move] == 'X' || boardARR[move] == '0') {
                cout << "Invalid move. Try again." << endl;
                continue;
            }

            boardARR[move] = player;

            if (checkwin(player)) {
                displayBoard();
                cout << "Player " << player << " wins!" << endl;
                break;
            }

            if (checkdraw()) {
                displayBoard();
                cout << "It's a draw!" << endl;
                break;
            }

            player = (player == 'X') ? '0' : 'X'; // Switch player
        }

        cout << "Do you want to play again? (y/n): ";
        cin >> playAgian;
    } while (playAgian == 'y' || playAgian == 'Y');
    
    cout<<"Thank you for playing the game\n";
return 0;
}
