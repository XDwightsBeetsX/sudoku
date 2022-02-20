#ifndef SUDOKUWRITER_H
#define SUDOKUWRITER_H

#include <string>
#include <vector>


/**
 * @brief Contains methods to write a sudoku to file. 
 */
class SudokuWriter {
    private:
        static std::string CM_PREFIX;
        static std::string DefaultOutputFilename;

    public:
        /**
         * @brief Writes a sudoku puzzle to outputFilename.
         * 
         * @param outputFilename The desired output filepath with the filename.
         */
        static void writeToFile(std::vector<std::vector<int>> &sudoku, std::string &outputFilename);
};

#endif