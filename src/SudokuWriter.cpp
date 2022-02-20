
#include "SudokuWriter.h"

#include <iostream>
#include <fstream>

using namespace std;


// set static data members for reference
string SudokuWriter::CM_PREFIX = "[SudokuWriter] - ";
string SudokuWriter::DefaultOutputFilename = "output/output.csv";


void SudokuWriter::writeToFile(vector<vector<int>> &sudoku, string &outputFilename) {
    cout << SudokuWriter::CM_PREFIX << "Writing '" << outputFilename << "'..." << endl;

    // write sudoku to an ofstream
    ofstream OutputFile;
    try {
        OutputFile.open(outputFilename);

        for (int row = 0; row < sudoku.size(); row++) {
            for (int col = 0; col < sudoku[0].size(); col++) {
                OutputFile << sudoku[row][col];

                // between all values, add a comma
                if (col < sudoku[0].size()-1)
                    OutputFile << ',';
            }

            // insert a newline after every line
            if (row < sudoku.size()-1)
                OutputFile << endl;
        }
        
        OutputFile.close();
        cout << SudokuWriter::CM_PREFIX << "Done writing '" << outputFilename << "'." << endl;
    }
    // issues writing to file such as invalid filename
    catch(const std::exception& e) {
        OutputFile.close();  // make sure the file got closed
        cout << SudokuWriter::CM_PREFIX << "There was an error writing '" << outputFilename << "'." << endl;
        cout << SudokuWriter::CM_PREFIX << "Error Message:" << endl << e.what();
    }
}
