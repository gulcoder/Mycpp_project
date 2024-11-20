#include <iostream>
using namespace std;

char board[3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}}; // Game board
int player = 1; // Byter mellan spelare X och O
int choice; // Spelarens val
int row, col; // Rad och kolumn där spelaren vill sätta sitt märke
char mark; // Spelarens märke (X eller O)

void displayBoard() {
    // Visa spelbrädet
    cout << "\n\nTic-Tac-Toe Game\n\n";
    cout << "Player 1 (X)  -  Player 2 (O)\n\n";
    cout << "     |     |     \n";
    cout << "  " << board[0][0] << "  |  " << board[0][1] << "  |  " << board[0][2] << " \n";
    cout << "_____|_____|_____\n";
    cout << "     |     |     \n";
    cout << "  " << board[1][0] << "  |  " << board[1][1] << "  |  " << board[1][2] << " \n";
    cout << "_____|_____|_____\n";
    cout << "     |     |     \n";
    cout << "  " << board[2][0] << "  |  " << board[2][1] << "  |  " << board[2][2] << " \n";
    cout << "     |     |     \n\n";
}

bool checkWin() {
    // Kontrollera alla vinstvillkor (horisontellt, vertikalt, diagonalt)
    for (int i = 0; i < 3; i++) {
        // Horisontella och vertikala kontroller
        if ((board[i][0] == board[i][1] && board[i][1] == board[i][2]) || (board[0][i] == board[1][i] && board[1][i] == board[2][i])) {
            return true;
        }
    }
    // Diagonal kontroll
    if ((board[0][0] == board[1][1] && board[1][1] == board[2][2]) || (board[0][2] == board[1][1] && board[1][1] == board[2][0])) {
        return true;
    }
    return false;
}

bool checkDraw() {
    // Kontrollera om alla platser på brädet är fyllda och ingen har vunnit
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] != 'X' && board[i][j] != 'O') {
                return false;
            }
        }
    }
    return true;
}

void playerTurn() {
    // Välj spelarens märke (X eller O)
    if (player % 2 != 0) {
        mark = 'X';
    } else {
        mark = 'O';
    }

    // Fråga spelaren om var de vill sätta sitt märke
    cout << "Player " << player << ", enter a number (1-9): ";
    cin >> choice;

    // Beräkna rad och kolumn baserat på spelarens val
    switch (choice) {
        case 1: row = 0; col = 0; break;
        case 2: row = 0; col = 1; break;
        case 3: row = 0; col = 2; break;
        case 4: row = 1; col = 0; break;
        case 5: row = 1; col = 1; break;
        case 6: row = 1; col = 2; break;
        case 7: row = 2; col = 0; break;
        case 8: row = 2; col = 1; break;
        case 9: row = 2; col = 2; break;
        default:
            cout << "Invalid move! Please try again.\n";
            playerTurn();
            return;
    }

    // Kontrollera om platsen är upptagen
    if (board[row][col] != 'X' && board[row][col] != 'O') {
        // Sätt spelarens märke på den valda platsen
        board[row][col] = mark;
        player++;
    } else {
        cout << "Cell already filled! Try again.\n";
        playerTurn();
    }
}

int main() {
    cout << "Welcome to Tic-Tac-Toe!\n";
    displayBoard();

    while (true) {
        displayBoard();
        playerTurn();

        // Kontrollera om en spelare har vunnit
        if (checkWin()) {
            displayBoard();
            cout << "Player " << (player % 2 == 0 ? 1 : 2) << " wins!\n";
            break;
        }

        // Kontrollera om det är oavgjort
        if (checkDraw()) {
            displayBoard();
            cout << "It's a draw!\n";
            break;
        }
    }

    return 0;
}
