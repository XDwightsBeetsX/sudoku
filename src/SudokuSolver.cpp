#include "SudokuSolver.h"
#include "utils.h"

#include <iostream>

using namespace std;

SudokuSolver::SudokuSolver(string inputFilename) {
    this->InputFilename = inputFilename;

    // use a SudokuReader to read in a puzzle to Problem and Solution
    this->SReader = new SudokuReader(inputFilename);
    vector<vector<int>> input = this->SReader->readProblem();
    this->Problem = input;
    this->Solution = input;
    delete this->SReader;                   // ok to delete this guy after using him to read input
    
    vector<string> folderSplit = split(inputFilename, "/");
    string outputFilename = "output/" + split(folderSplit[folderSplit.size()-1], ".")[0] + "-out.csv";
    this->OutputFilename = outputFilename;
    this->SWriter = new SudokuWriter();     // need to keep around for writeSolutionToFile()
}

SudokuSolver::~SudokuSolver() {
    // delete dynamically allocated memory
    delete this->SWriter;
    delete this;
}

void SudokuSolver::printSudoku(vector<vector<int>> &sudoku) {
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

void SudokuSolver::showProblem() {
    cout << this->CM_PREFIX << "Sudoku Problem:" << endl;
    this->printSudoku(this->Problem);
}

void SudokuSolver::showSolution() {
    cout << this->CM_PREFIX << "Sudoku Solution:" << endl;
    this->printSudoku(this->Solution);
}

void SudokuSolver::writeSolutionToFile(string outputFilename) {
    // can specify a custom filename, or use the determined this->OutputFilename
    if (outputFilename == "") {
        this->SWriter->writeToFile(this->Solution, this->OutputFilename);
    }
    else {
        this->SWriter->writeToFile(this->Solution, outputFilename);
    }
}

vector<int> SudokuSolver::getNextRowAndCol() {
    vector<int> nextRowAndCol = {-1, -1};
    for (int row = 0; row < 9; row++) {
        for (int col = 0; col < 9; col++) {
            if (SudokuRules::isEmptyCell(this->Solution, row, col)) {
                nextRowAndCol[0] = row;
                nextRowAndCol[1] = col;
            }
        }
    }

    return nextRowAndCol;
}

bool SudokuSolver::recursiveSolve() {
    vector<int> rowAndCol = this->getNextRowAndCol();

    // see if this is the last empty cell
    if (rowAndCol[0] == -1 || rowAndCol[1] == -1)
        return true;
    
    int row = rowAndCol[0];
    int col = rowAndCol[1];
    
    // plug in all values into all empty cells recursively
    for (int val = 1; val <= 9; val++) {
        if (SudokuRules::isValid(this->Solution, row, col, val)) {
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

bool SudokuSolver::solve() {
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
