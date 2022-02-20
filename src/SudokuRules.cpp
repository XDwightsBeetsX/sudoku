#include "SudokuRules.h"

using namespace std;


bool SudokuRules::isValid(vector<vector<int>> &sudoku, int &row, int &col, int &value) {
    return SudokuRules::isValidRow(sudoku, row, value) && SudokuRules::isValidCol(sudoku, col, value) && SudokuRules::isValidSquare(sudoku, row, col, value);
}


bool SudokuRules::isEmptyCell(vector<vector<int>> &sudoku, int &row, int &col) {
    return sudoku[row][col] == 0;
}


bool SudokuRules::isValidRow(vector<vector<int>> &sudoku, int &row, int &value) {
    for (int col = 0; col < sudoku[0].size(); col++) {
        if (sudoku[row][col] == value)
            return false;
    }

    return true;
}


bool SudokuRules::isValidCol(vector<vector<int>> &sudoku, int &col, int &value) {
    for (int row = 0; row < sudoku.size(); row++) {
        if (sudoku[row][col] == value)
            return false;
    }

    return true;
}


bool SudokuRules::isValidSquare(vector<vector<int>> &sudoku, int &row, int &col, int &value) {
    // perform integer division to get the square
    // then, multiply by 3 to get the row index
    int squareRowI = (row / 3) * 3;
    int squareColI = (col / 3) * 3;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (sudoku[squareRowI + i][squareColI + j] == value)
                return false;
        }
    }

    return true;
}