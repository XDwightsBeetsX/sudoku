#ifndef SUDOKUREADER_H
#define SUDOKUREADER_H

#include <string>
#include <vector>


/**
 * @brief Contains methods to read a sudoku problem from file. 
 */
class SudokuReader {
    private:
        const std::string CM_PREFIX = "[SukoduReader] - ";
        const std::string DefaultInputFilename = "input/input.csv";
        std::string InputFilename;
        
    public:
        /**
         * @brief Construct a new Sudoku Reader object.
         * NOTE: This is not the recommended construction since the default InputFilename will be used.
         */
        SudokuReader();

        /**
         * @brief Construct a new Sudoku Reader object from an inputFilename.
         * 
         * @param inputFilename The relative path to the input.csv file.
         */
        SudokuReader(std::string inputFilename);

        /**
         * @brief Reads the sudoku problem from the input file.
         * NOTE: The expected format is a .csv of size 9x9.
         */
        std::vector<std::vector<int>> readProblem();
};

#endif