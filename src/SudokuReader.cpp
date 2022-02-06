
#include "SudokuReader.h"

#include <iostream>
#include <fstream>


using namespace std;

SudokuReader::SudokuReader() {
    cout << this->CM_PREFIX << "Empty SudokuReader constructed." << endl;
    cout << this->CM_PREFIX << "Using default inputFilename: " << this->DefaultInputFilename << endl;
    this->InputFilename = this->DefaultInputFilename;
}

SudokuReader::SudokuReader(string inputFilename) {
    cout << this->CM_PREFIX << "SudokuReader constructed with input filename: '" << inputFilename << "'" << endl;
    this->InputFilename = inputFilename;
}

vector<vector<int>> SudokuReader::readProblem() {
    cout << this->CM_PREFIX << "Reading '" << this->InputFilename << "'..." << endl;

    // setup data holders for the problem, File, and line
    vector<vector<int>> problem = vector<vector<int>>(9, vector<int>(9, 0));
    ifstream InputFile(this->InputFilename);
    string line;

    // read File and parse each line into integers for problem
    while (getline(InputFile, line)) {
        cout << line << endl;
    }

    cout << CM_PREFIX << "Done reading '" << this->InputFilename << "'" << endl;
    return problem;
}
