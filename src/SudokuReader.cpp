
#include "SudokuReader.h"

#include <iostream>
#include <fstream>


using namespace std;

int* SudokuReader::readProblem() {
    ifstream InputFile(this->InputFilename);
    string line;
    while (getline(InputFile, line)) {
        cout << line << endl;
    }

    return nullptr;
}
