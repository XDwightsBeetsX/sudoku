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
        // const attributes
        const std::string CM_PREFIX = "[Sukodu] - ";

        // data members
        std::string InputFilename;
        std::string OutputFilename;

        SudokuReader* SR;
        SudokuWriter* SW;
        std::vector<std::vector<int>> Problem;
        std::vector<std::vector<int>> Solution;

        // helpers
        /**
         * @brief Displays the sudoku board to console.
         */
        void printSudoku(std::vector<std::vector<int>>);
        
        /**
         * @brief Determines if placing value into sudoku at [row, col] is a valid move.
         * 
         * @param sudoku The sudoku puzzle.
         * @param row The row location to insert value at.
         * @param col The col location to insert value at.
         * @param value The value to insert.
         * @return true Placing value into sudoku at [row,col] is valid.
         * @return false Placing value into sudoku at [row,col] is invalid.
         */
        bool isValid(std::vector<std::vector<int>> sudoku, int row, int col, int value);
        
        /**
         * @brief Determines if placing value into the sudoku row is a valid move.
         * 
         * @param sudoku The sudoku puzzle.
         * @param row The row location to insert value at.
         * @param value The value to insert.
         * @return true Placing value into the sudoku row is valid.
         * @return false Placing value into the sudoku row is invalid.
         */
        bool isValidRow(std::vector<std::vector<int>> sudoku, int row, int value);
        
        /**
         * @brief Determines if placing value into the sudoku col is a valid move.
         * 
         * @param sudoku The sudoku puzzle.
         * @param col The col location to insert value at.
         * @param value The value to insert.
         * @return true Placing value into the sudoku col is valid.
         * @return false Placing value into the sudoku col is invalid.
         */
        bool isValidCol(std::vector<std::vector<int>> sudoku, int row, int value);
        
        /**
         * @brief Determines if placing value into the sudoku square at [row,col] is a valid move.
         * 
         * @param sudoku The sudoku puzzle.
         * @param row The row location to insert value at.
         * @param col The col location to insert value at.
         * @param value The value to insert.
         * @return true Placing value into the sudoku square at [row,col] is valid.
         * @return false Placing value into the sudoku square at [row,col] is invalid.
         */
        bool isValidSquare(std::vector<std::vector<int>> sudoku, int row, int col, int value);
    
    public:
        /**
         * @brief Requires an reading inputFilename to create.
         * 
         * @param inputFilename The relative path to the input.csv file.
         */
        Sudoku(std::string inputFilename);

        /**
         * @brief Destroy the Sudoku object
         * 
         */
        ~Sudoku();

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