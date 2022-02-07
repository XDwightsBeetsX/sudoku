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
         * @param row The row location to insert value at.
         * @param col The col location to insert value at.
         * @param value The value to insert.
         * @return true Placing value into sudoku at [row,col] is valid.
         * @return false Placing value into sudoku at [row,col] is invalid.
         */
        bool isValid(int row, int col, int value);
        
        /**
         * @brief Determines whether the desired cell is empty.
         * 
         * @param row The row location.
         * @param col The col location.
         * @return true Sudoku at [row,col] is empty.
         * @return false Sudoku at [row,col] is occupied.
         */
        bool isEmptyCell(int row, int col);

        /**
         * @brief Determines if placing value into the sudoku row is a valid move.
         * 
         * @param row The row location to insert value at.
         * @param value The value to insert.
         * @return true Placing value into the sudoku row is valid.
         * @return false Placing value into the sudoku row is invalid.
         */
        bool isValidRow(int row, int value);
        
        /**
         * @brief Determines if placing value into the sudoku col is a valid move.
         * 
         * @param col The col location to insert value at.
         * @param value The value to insert.
         * @return true Placing value into the sudoku col is valid.
         * @return false Placing value into the sudoku col is invalid.
         */
        bool isValidCol(int row, int value);
        
        /**
         * @brief Determines if placing value into the sudoku square at [row,col] is a valid move.
         * 
         * @param row The row location to insert value at.
         * @param col The col location to insert value at.
         * @param value The value to insert.
         * @return true Placing value into the sudoku square at [row,col] is valid.
         * @return false Placing value into the sudoku square at [row,col] is invalid.
         */
        bool isValidSquare(int row, int col, int value);

        /**
         * @brief Gets the next available [row, col]
         * 
         * @return vector<int> A vector with the next available row and column, respectively.
         */
        std::vector<int> getNextRowAndCol();

        /**
         * @brief A helper method of Sudoku::solve()
         * 
         * @return true There exists a solution to the Problem.
         * @return false There was no solution found to the Problem.
         */
        bool recursiveSolve();
    
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
         * @brief Displays the sudoku problem solution in the console.
         */
        void showSolution();

        /**
         * @brief Writes the sudoku problem solution to the output folder with the same filename as the input file.
         */
        void writeSolutionToFile();

        /**
         * @brief Generates a solution to the input sudoku problem.
         * 
         * @return true There is a solution to the Problem (kept in Sudoku->Solution).
         * @return false There is no solution for this Problem (Sudoku->Solution reset to 0s).
         */
        bool solve();
};

#endif