
#include "Sudoku.h"
#include "SudokuReader.h"
#include "utils.h"

#include <iostream>

using namespace std;

Sudoku::Sudoku(string inputFilename) {
    this->InputFilename = inputFilename;

    this->SR = new SudokuReader(inputFilename);
    vector<vector<int>> input = this->SR->readProblem();
    this->Problem = input;
    this->Solution = input;
    
    vector<string> folderSplit = split(inputFilename, "/");
    string outputFilename = "output/" + split(folderSplit[folderSplit.size()-1], ".")[0] + "-out.csv";
    this->OutputFilename = outputFilename;
    this->SW = new SudokuWriter(outputFilename);
}

Sudoku::~Sudoku() {
    // delete dynamically allocated memory
    delete this->SR;
    delete this->SW;
}

void Sudoku::printSudoku(vector<vector<int>> sudoku) {
    for (int row = 0; row < sudoku.size(); row++) {
        // print the row separators
        if (row == 3 || row == 6)
            cout << string(9*3+2, '-') << endl;
        
        for (int col = 0; col < sudoku[0].size(); col++) {
            // prints column separators
            if (col == 3 || col == 6)
                cout << "|";
            
            // pad the Problem cell value
            cout << " " << sudoku[row][col] << " ";
        }
        // every row starts on a newline
        cout << endl;
    }
}

void Sudoku::showProblem() {
    cout << this->CM_PREFIX << "Sudoku Problem:" << endl;
    this->printSudoku(this->Problem);
}

void Sudoku::showSolution() {
    cout << this->CM_PREFIX << "Sudoku Solution:" << endl;
    this->printSudoku(this->Solution);
}

void Sudoku::writeSolutionToFile() {
    this->SW->writeToFile(this->Solution);
}

bool Sudoku::isValid(int row, int col, int value) {
    return this->isValidRow(row, value) && this->isValidCol(col, value) && this->isValidSquare(row, col, value);
}

bool Sudoku::isEmptyCell(int row, int col) {
    return this->Solution[row][col] == 0;
}

bool Sudoku::isValidRow(int row, int value) {
    for (int col = 0; col < this->Solution[0].size(); col++) {
        if (this->Solution[row][col] == value)
            return false;
    }

    return true;
}

bool Sudoku::isValidCol(int col, int value) {
    for (int row = 0; row < this->Solution.size(); row++) {
        if (this->Solution[row][col] == value)
            return false;
    }

    return true;
}

bool Sudoku::isValidSquare(int row, int col, int value) {
    // perform integer division to get the square
    // then, multiply by 3 to get the row index
    int squareRowI = (row / 3) * 3;
    int squareColI = (col / 3) * 3;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (this->Solution[squareRowI + i][squareColI + j] == value)
                return false;
        }
    }

    return true;
}

vector<int> Sudoku::getNextRowAndCol() {
    vector<int> nextRowAndCol = {-1, -1};
    for (int row = 0; row < 9; row++) {
        for (int col = 0; col < 9; col++) {
            if (this->isEmptyCell(row, col)) {
                nextRowAndCol[0] = row;
                nextRowAndCol[1] = col;
            }
        }
    }

    return nextRowAndCol;
}

bool Sudoku::recursiveSolve() {
    vector<int> rowAndCol = this->getNextRowAndCol();

    // see if this is the last empty cell
    if (rowAndCol[0] == -1 || rowAndCol[1] == -1)
        return true;
    
    int row = rowAndCol[0];
    int col = rowAndCol[1];
    
    // plug in all values into all empty cells recursively
    for (int val = 1; val <= 9; val++) {
        if (this->isValid(row, col, val)) {
            // if the move is valid, place val in [row][col]
            this->Solution[row][col] = val;

            // continue on to the next cells
            if (this->recursiveSolve()) {
                return true;
            }

            // reset if not part of the solution
            this->Solution[row][col] = 0;
        }
    }

    return false;
}

bool Sudoku::solve() {
    cout << this->CM_PREFIX << "Solving..." << endl;

    // call the recursive helper
    if (this->recursiveSolve()) {
        cout << this->CM_PREFIX << "Done solving." << endl;
        return true;
    }
    
    // reset the solution
    this->Solution = this->Problem;
    cout << this->CM_PREFIX << "No solution found. Writing the solution will re-write the sudoku input." << endl;
    return false;
}
