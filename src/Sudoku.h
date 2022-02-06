#ifndef SUDOKU_H
#define SUDOKU_H

#include "SudokuReader.h"
#include "SudokuWriter.h"

#include <string>

/**
 * @brief Main class of the sudoku-solver project.
 * Contains methods like solve() and writeSolutionToFile().
 */
class Sudoku {
    private:
        const std::string CM_PREFIX = "[Sukodu] - ";

        std::string InputFilename;
        std::string OutputFilename;

        SudokuReader* SR;
        SudokuWriter* SW;
        std::vector<std::vector<int>> Problem;

        void printSudoku(std::vector<std::vector<int>>);
    public:
        /**
         * @brief Requires an reading inputFilename to create.
         * 
         * @param inputFilename The relative path to the input.csv file.
         */
        Sudoku(std::string inputFilename);

        /**
         * @brief Displays the input sudoku problem to the console.
         */
        void showProblem();

        /**
         * @brief Generates a solution to the input sudoku problem.
         */
        void solve();

        /**
         * @brief Displays the sudoku problem solution in the console.
         */
        void showSolution();

        /**
         * @brief Writes the sudoku problem solution to the output folder with the same filename as the input file.
         */
        void writeSolutionToFile();
};

#endif