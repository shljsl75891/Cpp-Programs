#include <iostream>
using namespace std;
int ans[9][9];

void printSudoku(int sudoku[][9]) {
    for(int i = 0; i < 9; i++) {
        for(int j = 0; j < 9; j++) {
            cout << sudoku[i][j] << " ";
        } cout << "\n";
    }
}

bool isSafe(int sudoku[][9], int row, int col, int val) {
    // finding the belonging 3x3 sub-matrix
    int khunjaRow = 3*(row/3), khunjaColumn = 3*(col/3);
    // checking for row
    for(int i = 0; i < 9; i++) {
        if(sudoku[row][i] == val) {
            return false;
        }
    }
    // checking for column
    for(int i = 0; i < 9; i++) {
        if(sudoku[i][col] == val) {
            return false;
        }
    }
    // checking for 3x3 matrix
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            if(sudoku[khunjaRow + i][khunjaColumn + j] == val) {
                return false;
            }
        }
    } return true;
}

void solveSudoku(int sudoku[][9], int i = 0, int j = 0) {
    // sudoku solve, base case
    if(i == 9) {
        cout << "After Solving Sudoku: \n";
        printSudoku(sudoku);
        return;
    } 
    // next cell coordinates
    int ni, nj;
    if(j == 8) {
        ni = i + 1;
        nj = 0;
    } else {
        ni = i;
        nj = j + 1;
    }
    // if cell is empty
    if(sudoku[i][j] == 0) {
        for(int val = 1; val <= 9; val++) {
            if(isSafe(sudoku, i, j, val)) {
                sudoku[i][j] = val;
                solveSudoku(sudoku, ni, nj);
                sudoku[i][j] = 0;
            }
        }
    } else {
        // cell not empty-> just ignore it
        solveSudoku(sudoku, ni, nj);
    }
}

int main() {
    int sudoku[9][9];
    for(int i = 0; i < 9; i++) {
        for(int j = 0; j < 9; j++) {
            cin >> sudoku[i][j];
        }
    } solveSudoku(sudoku);
}

