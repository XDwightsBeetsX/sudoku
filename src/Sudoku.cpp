
#include "Sudoku.h"
#include "SudokuReader.h"
#include "utils.h"

#include <iostream>

using namespace std;

Sudoku::Sudoku(string inputFilename) {
    this->InputFilename = inputFilename;

    this->SR = new SudokuReader(inputFilename);
    this->Problem = this->SR->readProblem();

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

void Sudoku::solve() {
    cout << this->CM_PREFIX << "Solving..." << endl;

    this->Solution = this->Problem;
    
    cout << this->CM_PREFIX << "Done solving." << endl;
}

bool Sudoku::isValid(vector<vector<int>> sudoku, int row, int col, int value) {
    if (this->isValidRow(sudoku, row, value)) {
        if (this->isValidCol(sudoku, col, value)) {
            if (this->isValidSquare(sudoku, row, col, value)) {
                return true;
            }
        }
    }
    return false;
}

bool Sudoku::isValidRow(vector<vector<int>> sudoku, int row, int value) {
    for (int col = 0; col < sudoku[0].size(); col++) {
        if (sudoku[row][col] == value)
            return false;
    }
    return true;
}

bool Sudoku::isValidCol(vector<vector<int>> sudoku, int col, int value) {
    for (int row = 0; row < sudoku.size(); row++) {
        if (sudoku[row][col] == value)
            return false;
    }
    return true;
}

bool Sudoku::isValidSquare(vector<vector<int>> sudoku, int row, int col, int value) {
    
}