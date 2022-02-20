#ifndef SUDOKU_H
#define SUDOKU_H

#include "SudokuRules.h"
#include "SudokuReader.h"
#include "SudokuWriter.h"


/**
 * @brief Main class of the sudoku-solver project.
 * Contains methods like solve() and writeSolutionToFile().
 */
class SudokuSolver {
    private:
        // const attributes
        const std::string CM_PREFIX = "[SukoduSolver] - ";

        // data members
        std::string InputFilename;
        std::string OutputFilename;

        SudokuReader* SReader;
        SudokuWriter* SWriter;
        
        std::vector<std::vector<int>> Problem;
        std::vector<std::vector<int>> Solution;

        // helpers
        /**
         * @brief Displays the sudoku board to console.
         */
        void printSudoku(std::vector<std::vector<int>> &sudoku);


        /**
         * @brief Gets the next available [row, col].
         * 
         * @return vector<int> A vector with the next available row and column, respectively.
         */
        std::vector<int> getNextRowAndCol();

        /**
         * @brief A helper method of solve()
         * 
         * @return true There exists a solution to the Problem.
         * @return false There was no solution found to the Problem.
         */
        bool recursiveSolve();
    
    public:
        /**
         * @brief Solving a puzzle requires reading from an inputFilename.
         * 
         * @param inputFilename The relative path to the input.csv file.
         */
        SudokuSolver(std::string inputFilename);

        /**
         * @brief Destroy the SudokuSolver object.
         */
        ~SudokuSolver();

        /**
         * @brief Displays the input sudoku problem to the console.
         */
        void showProblem();

        /**
         * @brief Displays the sudoku solution in the console.
         * NOTE: The Sudoku must be solved with solve() before a solution is found. Otherwise, the initial problem is shown.
         */
        void showSolution();

        /**
         * @brief Writes the sudoku problem solution to an output file.
         * Specify a custom outputFilename, or use the default (same name as input file in the output folder).
         * NOTE: The SudokuSolver must be solved with solve() before a solution is found. Otherwise, the initial problem will be written.
         * Use `if(SudokuSolver.solve()) { SudokuSolver.writeSolutionToFile(); }
         */
        void writeSolutionToFile(std::string outputFilename="");

        /**
         * @brief Generates a solution to the input sudoku problem.
         * 
         * @return true There is a solution to the problem. The Solution data member is updated.
         * @return false There is no solution for this Problem. The Solution data member is reset to the initial problem.
         */
        bool solve();
};

#endif