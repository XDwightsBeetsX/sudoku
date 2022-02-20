#ifndef SUDOKUGENERATOR_H
#define SUDOKUGENERATOR_H

#include "SudokuRules.h"
#include "SudokuWriter.h"

#include <vector>


/**
 * @brief Responsible for generating random sudoku puzzles to the generated/ folder.
 */
class SudokuGenerator {
    private:
        std::string CM_PREFIX = "[SudokuGenerator] - ";
        std::string F_GEN_PREFIX = "input/generated/gen_puzzle_";

    public:
        /**
         * @brief generates count puzzles to the input/ directory with sequential names.
         * Will overwrite existing files with the same names.
         * 
         * @param count the number of puzzles to create.
         */
        void generatePuzzles(int count);
};


#endif