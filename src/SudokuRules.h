#ifndef SUDOKURULES_H
#define SUDOKURULES_H

#include <vector>

/**
 * @brief Contains static methods for rules of sudoku.
 * These are used to determine if the placement of a value in a cell is valid.
 */
class SudokuRules {
    public:
        /**
         * @brief Determines if placing value into sudoku at [row, col] is a valid move.
         * 
         * @param sudoku a reference to the 2D sudoku array to check
         * @param row the row location to check validity
         * @param col the column location to check validity
         * @param value the value to check validity
         * @return true Placing value into sudoku at [row,col] is valid.
         * @return false Placing value into sudoku at [row,col] is invalid.
         */
        static bool isValid(std::vector<std::vector<int>> &sudoku, int &row, int &col, int &value);

        /**
         * @brief Determines whether the desired cell is empty.
         * 
         * @param sudoku a reference to the 2D sudoku array to check
         * @param row the row location to check if the cell is empty
         * @param col the column location to check if the cell is empty
         * @return true if placing the value in the square at [row, col] is valid
         * @return false if placing the value in the square at [row, col] is invalid
         */
        static bool isEmptyCell(std::vector<std::vector<int>> &sudoku, int &row, int &col);

        /**
         * @brief Determines if placing value into the sudoku row is a valid move.
         * 
         * @param sudoku a reference to the 2D sudoku array to check
         * @param row the row location to check if the cell is empty
         * @param value the value to check validity
         * @return true if placing the value in the square at [row, col] is valid
         * @return false if placing the value in the square at [row, col] is invalid
         */
        static bool isValidRow(std::vector<std::vector<int>> &sudoku, int &row, int &value);

        /**
         * @brief Determines if placing value into the sudoku col is a valid move.
         * 
         * @param sudoku a reference to the 2D sudoku array to check
         * @param col the column location to check validity
         * @param value the value to check validity
         * @return true if placing the value in the square at [row, col] is valid
         * @return false if placing the value in the square at [row, col] is invalid
         */
        static bool isValidCol(std::vector<std::vector<int>> &sudoku, int &row, int &value);

        /**
         * @brief Determines if placing value into the sudoku square at [row,col] is a valid move.
         * 
         * @param sudoku a reference to the 2D sudoku array to check
         * @param row the row location to check validity
         * @param col the column location to check validity
         * @param value the value to check validity
         * @return true if placing the value in the square at [row, col] is valid
         * @return false if placing the value in the square at [row, col] is invalid
         */
        static bool isValidSquare(std::vector<std::vector<int>> &sudoku, int &row, int &col, int &value);
};


#endif