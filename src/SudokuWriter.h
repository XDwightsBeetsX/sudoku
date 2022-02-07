#ifndef SUDOKUWRITER_H
#define SUDOKUWRITER_H

#include <string>
#include <vector>


/**
 * @brief Contains methods to write a sudoku to file. 
 */
class SudokuWriter {
    private:
        const std::string CM_PREFIX = "[SudokuWriter] - ";
        const std::string DefaultOutputFilename = "output/output.csv";
        std::string OutputFilename;

    public:
        /**
         * @brief Construct a new Sudoku Writer object.
         * NOTE: This is not the recommended construction since the default OutputFilename will be used.
         */
        SudokuWriter();

        /**
         * @brief Construct a new Sudoku Writer object from an outputFilename.
         * 
         * @param outputFilename The relative path to the output.csv file.
         */
        SudokuWriter(std::string outputFilename);

        /**
         * @brief Writes a 2D vector to outputFilename.
         * 
         * @param outputFilename The desired output filepath with the filename.
         */
        void writeToFile(std::vector<std::vector<int>> sudoku);
};

#endif