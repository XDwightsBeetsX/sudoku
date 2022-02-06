
#include <string>

/**
 * @brief Contains methods to write a sudokuArray to file. 
 */
static class SudokuWriter {
    public:
        /**
         * @brief Writes the 2d integer array sudoku solution to file.
         * NOTE: The outputFilename is set from inputfilename
         * 
         * @param outputFilename The desired output filepath with the filename.
         */
        void writeToFile(std::string outputFilename, int* sudokuArray);
};
