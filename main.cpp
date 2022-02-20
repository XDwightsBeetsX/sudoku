/* Sudoku Solver in C++
 * 
 * 1. Write an input.csv in the format shown in `samples/`.
 * 2. Update the filename in the Sudoku constructor below.
 * 3. Run `make all` followed by `make run` to solve the puzzle.
 */

#include "src/SudokuSolver.h"
#include "src/SudokuGenerator.h"

using namespace std;

int main() {
    // // ============== FILENAME ===============
    // string inputFilename = "input/sample.csv";
    // // =======================================

    // SudokuSolver SS = SudokuSolver(inputFilename);
    // SS.showProblem();
    // if (SS.solve()) {
    //     SS.showSolution();
    //     SS.writeSolutionToFile();
    // }

    SudokuGenerator SG = SudokuGenerator();
    SG.generatePuzzles(10);


    return 0;
}
