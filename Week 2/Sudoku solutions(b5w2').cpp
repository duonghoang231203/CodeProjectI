//giai phap
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
                        board[row][col] = 0;  // Hoàn tác n?u không tìm du?c gi?i pháp h?p l?
                    }
                }
                return false;  // Không tìm du?c s? h?p l?, quay lui
            }
        }
    }
    return true;  // T?t c? các ô dã du?c di?n, tìm th?y gi?i pháp
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
    cout << "Gi?i pháp Sudoku:" << endl;
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
        cout << "Không có gi?i pháp." << endl;
    }

    return 0;
}
