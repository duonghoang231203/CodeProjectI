//giai phap
#include <iostream>
using namespace std;

bool is_valid(int board[9][9], int row, int col, int num) {
    // Ki?m tra xem s? d� t?n t?i trong h�ng hi?n t?i chua
    for (int i = 0; i < 9; i++) {
        if (board[row][i] == num) {
            return false;
        }
    }

    // Ki?m tra xem s? d� t?n t?i trong c?t hi?n t?i chua
    for (int i = 0; i < 9; i++) {
        if (board[i][col] == num) {
            return false;
        }
    }

    // Ki?m tra xem s? d� t?n t?i trong � con 3x3 hi?n t?i chua
    int subgrid_row = (row / 3) * 3;
    int subgrid_col = (col / 3) * 3;
    for (int i = subgrid_row; i < subgrid_row + 3; i++) {
        for (int j = subgrid_col; j < subgrid_col + 3; j++) {
            if (board[i][j] == num) {
                return false;
            }
        }
    }

    return true;
}

bool solve_sudoku(int board[9][9]) {
    for (int row = 0; row < 9; row++) {
        for (int col = 0; col < 9; col++) {
            if (board[row][col] == 0) {
                for (int num = 1; num <= 9; num++) {
                    if (is_valid(board, row, col, num)) {
                        board[row][col] = num;
                        if (solve_sudoku(board)) {
                            return true;
                        }
                        board[row][col] = 0;  // Ho�n t�c n?u kh�ng t�m du?c gi?i ph�p h?p l?
                    }
                }
                return false;  // Kh�ng t�m du?c s? h?p l?, quay lui
            }
        }
    }
    return true;  // T?t c? c�c � d� du?c di?n, t�m th?y gi?i ph�p
}

void input_sudoku(int board[9][9]) {
    cout << "Nh?p b?ng Sudoku (9x9):" << endl;
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cin >> board[i][j];
        }
    }
}

void print_sudoku(int board[9][9]) {
    cout << "Gi?i ph�p Sudoku:" << endl;
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int board[9][9];

    input_sudoku(board);

    if (solve_sudoku(board)) {
        print_sudoku(board);
    } else {
        cout << "Kh�ng c� gi?i ph�p." << endl;
    }

    return 0;
}
