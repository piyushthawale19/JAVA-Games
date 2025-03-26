#include <iostream>
#include <vector>

using namespace std;


const int ROWS = 6;
const int COLS = 7;
const char EMPTY = ' ';
const char PLAYER1 = 'X';
const char PLAYER2 = 'O';

void printBoard(const vector<vector<char>>& board) {
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) {
            cout << "| " << board[i][j] << " ";
        }
        cout << "|\n";
    }
    cout << "-----------------------------\n";
    cout << "| 1 | 2 | 3 | 4 | 5 | 6 | 7 |\n";
    cout << "-----------------------------\n";
}


bool isValidMove(const vector<vector<char>>& board, int col) {
    return col >= 0 && col < COLS && board[0][col] == EMPTY;
}


void makeMove(vector<vector<char>>& board, int col, char player) {
    for (int i = ROWS - 1; i >= 0; --i) {
        if (board[i][col] == EMPTY) {
            board[i][col] = player;
            break;
        }
    }
}

bool checkWin(const vector<vector<char>>& board, char player) {
    
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j <= COLS - 4; ++j) {
            if (board[i][j] == player && board[i][j + 1] == player &&
                board[i][j + 2] == player && board[i][j + 3] == player) {
                return true;
            }
        }
    }

    
    for (int i = 0; i <= ROWS - 4; ++i) {
        for (int j = 0; j < COLS; ++j) {
            if (board[i][j] == player && board[i + 1][j] == player &&
                board[i + 2][j] == player && board[i + 3][j] == player) {
                return true;
            }
        }
    }


    for (int i = 0; i <= ROWS - 4; ++i) {
        for (int j = 0; j <= COLS - 4; ++j) {
            if (board[i][j] == player && board[i + 1][j + 1] == player &&
                board[i + 2][j + 2] == player && board[i + 3][j + 3] == player) {
                return true;
            }
        }
    }


    for (int i = 3; i < ROWS; ++i) {
        for (int j = 0; j <= COLS - 4; ++j) {
            if (board[i][j] == player && board[i - 1][j + 1] == player &&
                board[i - 2][j + 2] == player && board[i - 3][j + 3] == player) {
                return true;
            }
        }
    }

    return false;
}

bool isBoardFull(const vector<vector<char>>& board) {
    for (int j = 0; j < COLS; ++j) {
        if (board[0][j] == EMPTY) {
            return false;
        }
    }
    return true;
}

int main() {
    vector<vector<char>> board(ROWS, vector<char>(COLS, EMPTY));
    bool player1Turn = true;

    cout << "Welcome to Connect 4!\n";

    while (true) {
        printBoard(board);

        char currentPlayer = (player1Turn) ? PLAYER1 : PLAYER2;
        int col;

        
        while (true) {
            cout << "Player " << currentPlayer << ", enter your move (1-7): ";

            if (!(cin >> col)) {  
                cout << "Invalid input! Please enter a number between 1 and 7.\n";
                cin.clear(); 
                cin.ignore(1000, '\n'); 
                continue;
            }

            col--; 

            if (isValidMove(board, col)) {
                break; 
            } else {
                cout << "Invalid move! Column full or out of range. Try again.\n";
            }
        }

        
        makeMove(board, col, currentPlayer);

        
        if (checkWin(board, currentPlayer)) {
            printBoard(board);
            cout << "Player " << currentPlayer << " wins!\n";
            break;
        }


        if (isBoardFull(board)) {
            printBoard(board);
            cout << "It's a tie!\n";
            break;
        }
        player1Turn = !player1Turn;
    }

    return 0;
}

