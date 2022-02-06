
#include "Sudoku.h"
#include "SudokuReader.h"

#include <iostream>

using namespace std;

Sudoku::Sudoku(string inputFilename) {
    this->SR = new SudokuReader(inputFilename);
    this->Problem = this->SR->readProblem();
}

void Sudoku::showProblem() {
    cout << this->CM_PREFIX << "Sudoku problem:" << endl;
    for (int row = 0; row < 9; row++) {
        // print the row separators
        if (row == 3 || row == 6)
            cout << string(9*3+2, '-') << endl;
        
        for (int col = 0; col < 9; col++) {
            // prints column separators
            if (col == 3 || col == 6)
                cout << "|";
            
            // pad the Problem cell value
            cout << " " << this->Problem[row][col] << " ";
        }
        // every row starts on a newline
        cout << endl;
    }
}

void Sudoku::solve() {

}

void Sudoku::showSolution() {

}

void Sudoku::writeSolutionToFile() {
    this->SW->writeToFile(this->OutputFilename);
}