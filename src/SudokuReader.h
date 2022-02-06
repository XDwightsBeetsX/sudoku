
#include <string>

/**
 * @brief Contains methods to read a sudoku problem from file. 
 */
class SudokuReader {
    private:
        std::string InputFilename;
    
    public:
        /**
         * @brief Construct a new Sudoku Reader object from an inputFilename
         * 
         * @param inputFilename The relative path to the input.csv file.
         */
        SudokuReader(std::string inputFilename) {
            InputFilename = inputFilename;
        }

        /**
         * @brief Reads the sudoku problem from the input file into a 2d integer array.
         * NOTE: The expected format is a .csv of size 9x9.
         */
        int* readProblem();
};
