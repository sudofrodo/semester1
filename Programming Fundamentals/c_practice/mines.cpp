#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

const int ROWS = 9;
const int COLS = 9;
const int MINES = 10;

struct Cell {
    bool isMine = false;
    bool revealed = false;
    bool flagged = false;
    int adjacentMines = 0;
};

vector<vector<Cell>> board(ROWS, vector<Cell>(COLS));

void placeMines() {
    int placed = 0;
    while (placed < MINES) {
        int r = rand() % ROWS;
        int c = rand() % COLS;
        if (!board[r][c].isMine) {
            board[r][c].isMine = true;
            placed++;
        }
    }
}

void calculateNumbers() {
    for (int r = 0; r < ROWS; r++) {
        for (int c = 0; c < COLS; c++) {
            if (board[r][c].isMine) continue;
            int count = 0;
            for (int dr = -1; dr <= 1; dr++) {
                for (int dc = -1; dc <= 1; dc++) {
                    int nr = r + dr, nc = c + dc;
                    if (nr >= 0 && nr < ROWS && nc >= 0 && nc < COLS && board[nr][nc].isMine)
                        count++;
                }
            }
            board[r][c].adjacentMines = count;
        }
    }
}

void reveal(int r, int c) {
    if (r < 0 || r >= ROWS || c < 0 || c >= COLS) return;
    if (board[r][c].revealed || board[r][c].flagged) return;

    board[r][c].revealed = true;

    if (board[r][c].adjacentMines == 0 && !board[r][c].isMine) {
        for (int dr = -1; dr <= 1; dr++)
            for (int dc = -1; dc <= 1; dc++)
                if (dr != 0 || dc != 0)
                    reveal(r + dr, c + dc);
    }
}

bool checkWin() {
    for (int r = 0; r < ROWS; r++)
        for (int c = 0; c < COLS; c++)
            if (!board[r][c].isMine && !board[r][c].revealed)
                return false;
    return true;
}

void printBoard(bool revealAll = false) {
    cout << "   ";
    for (int c = 0; c < COLS; c++)
        cout << c << ' ';
    cout << endl;

    for (int r = 0; r < ROWS; r++) {
        cout << r << "  ";
        for (int c = 0; c < COLS; c++) {
            if (revealAll) {
                if (board[r][c].isMine) cout << '*';
                else if (board[r][c].adjacentMines > 0) cout << board[r][c].adjacentMines;
                else cout << ' ';
            } else if (board[r][c].flagged)
                cout << 'F';
            else if (!board[r][c].revealed)
                cout << '#';
            else if (board[r][c].isMine)
                cout << '*';
            else if (board[r][c].adjacentMines > 0)
                cout << board[r][c].adjacentMines;
            else
                cout << ' ';
            cout << ' ';
        }
        cout << endl;
    }
}

int main() {
    srand(time(0));
    placeMines();
    calculateNumbers();

    bool gameOver = false;

    while (!gameOver) {
        printBoard();
        cout << "Enter command (r row col = reveal, f row col = flag): ";
        char cmd;
        int r, c;
        cin >> cmd >> r >> c;

        if (cmd == 'r') {
            if (board[r][c].flagged) {
                cout << "Cell is flagged! Unflag before revealing.\n";
                continue;
            }
            reveal(r, c);
            if (board[r][c].isMine) {
                cout << "Boom! You hit a mine. Game Over.\n";
                gameOver = true;
                printBoard(true);
            } else if (checkWin()) {
                cout << "Congratulations! You cleared the board!\n";
                gameOver = true;
                printBoard(true);
            }
        } else if (cmd == 'f') {
            if (!board[r][c].revealed)
                board[r][c].flagged = !board[r][c].flagged;
        } else {
            cout << "Invalid command.\n";
        }
    }

    return 0;
}
