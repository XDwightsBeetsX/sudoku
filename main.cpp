/* Sudoku Solver in C++
 * 
 * 1. Write an input.csv in the format shown in `samples/`.
 * 2. Update the filename in the Sudoku constructor below.
 * 3. Run `make all` followed by `make run` to solve the puzzle.
 */

#include "src/Sudoku.h"

using namespace std;

int main() {
    // ============== FILENAME ===============
    string inputFilename = "input/sample.csv";
    // =======================================

    Sudoku S = Sudoku(inputFilename);
    S.showProblem();
    if (S.solve()) {
        S.showSolution();
        S.writeSolutionToFile();
    }

    return 0;
}
