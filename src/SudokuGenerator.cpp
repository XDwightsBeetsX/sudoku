#include "SudokuGenerator.h"

#include <iostream>

using namespace std;

void SudokuGenerator::generatePuzzles(int count) {
    cout << SudokuGenerator::CM_PREFIX << "Generating " << count << " puzzles..." << endl;

    int minCellVals = 17;   // well-known that 17 is the minimum needed for a solvable puzzle
    int maxCellVals = 30;

    for (int pn = 1; pn <= count; pn++) {
        cout << SudokuGenerator::CM_PREFIX << "Generating puzzle #" << pn << "..." << endl;

        // init each puzzle to empty 2d vector
        vector<vector<int>> puzzle(9, vector<int>(9, 0));

        // insert a number into [minCellVals, maxCellVals] cells
        int cellsToFill = rand() % (maxCellVals - minCellVals) + minCellVals;

        int row = rand() % 9;
        int col = rand() % 9;
        int val = rand() % 9 + 1;
        for (int c = 0; c < cellsToFill; c++) {
            // generate new [row, col, val]s until cell is good to fill
            while (! SudokuRules::isValid(puzzle, row, col, val)) {
                row = rand() % 9;
                col = rand() % 9;
                val = rand() % 9 + 1;
            }
            puzzle[row][col] = val;
        }

        // write the puzzle to input/generated/ folder
        string outputFilename = SudokuGenerator::F_GEN_PREFIX + to_string(pn) + ".csv";
        SudokuWriter::writeToFile(puzzle, outputFilename);
    }

    cout << SudokuGenerator::CM_PREFIX << "Successfully generated and write " << count << " puzzles." << endl;
}