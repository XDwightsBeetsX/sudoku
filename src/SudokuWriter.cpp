
#include "SudokuWriter.h"

#include <iostream>
#include <fstream>

using namespace std;

SudokuWriter::SudokuWriter() {
    cout << this->CM_PREFIX << "Empty SudokuWriter constructed." << endl;
    cout << this->CM_PREFIX << "Using default outputFilename: " << this->DefaultOutputFilename << endl;
    this->OutputFilename = this->DefaultOutputFilename;
}

SudokuWriter::SudokuWriter(string outputFilename) {
    cout << this->CM_PREFIX << "SudokuWriter constructed with output filename: '" << outputFilename << "'" << endl;
    this->OutputFilename = outputFilename;
}

void SudokuWriter::writeToFile(vector<vector<int>> sudoku) {
    cout << this->CM_PREFIX << "Writing '" << this->OutputFilename << "'..." << endl;

    ofstream OutputFile(this->OutputFilename);

    for (int row = 0; row < sudoku.size(); row++) {
        for (int col = 0; col < sudoku[0].size(); col++) {
            OutputFile << sudoku[row][col];
            if (col < sudoku[0].size()-1)
                OutputFile << ',';
        }
        if (row < sudoku.size()-1)
            OutputFile << endl;
    }
    OutputFile.close();
    
    cout << CM_PREFIX << "Done writing '" << this->OutputFilename<< "'" << endl;
}
