/* Sudoku Solver in C++
 * write an input.txt in the format shown in samples/
 * run `make all` followed by `make run` to solve the puzzle
 */

#include "src/Sudoku.h"
#include "src/SudokuReader.h"

#include <iostream>

using namespace std;

int main() {
    /** TODO:
     * start w reader
     * make Sudoku so that it has its own reader and writer
     * make writer
     * just write through a problem to file
     * make Sudoku.solve()
     */

    SudokuReader SR = SudokuReader("input/sample.csv");
    int* sudokuPuzzle = SR.readProblem();

    return 0;
}
