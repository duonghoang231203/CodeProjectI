//so giai phap
#include <iostream>
using namespace std;

bool is_valid(int board[9][9], int row, int col, int num) {
    // Ki?m tra xem s? dã t?n t?i trong hàng hi?n t?i chua
    for (int i = 0; i < 9; i++) {
        if (board[row][i] == num) {
            return false;
        }
    }

    // Ki?m tra xem s? dã t?n t?i trong c?t hi?n t?i chua
    for (int i = 0; i < 9; i++) {
        if (board[i][col] == num) {
            return false;
        }
    }

    // Ki?m tra xem s? dã t?n t?i trong ô con 3x3 hi?n t?i chua
    int subgrid_row = (row / 3) * 3; // +3 de dam bao rang da duyet qua tat ca cac o trong o con
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

int solve_sudoku(int board[9][9]) {
    int count = 0;

    for (int row = 0; row < 9; row++) {
        for (int col = 0; col < 9; col++) {
            if (board[row][col] == 0) {
                for (int num = 1; num <= 9; num++) {
                    if (is_valid(board, row, col, num)) {
                        board[row][col] = num;
                        count += solve_sudoku(board);
                        board[row][col] = 0;  // Hoàn tác n?u không tìm du?c gi?i pháp h?p l?
                    }
                }
                return count;  // Tr? v? s? lu?ng gi?i pháp
            }
        }
    }

    return 1;  // T?t c? các ô dã du?c di?n, tìm th?y m?t gi?i pháp
}

void input_sudoku(int board[9][9]) {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cin >> board[i][j];
        }
    }
}

int main() {
    int board[9][9];

    input_sudoku(board);

    int solutions = solve_sudoku(board);
    cout << solutions << endl;

    return 0;
}

