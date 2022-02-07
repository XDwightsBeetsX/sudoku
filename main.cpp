/* Sudoku Solver in C++
 * write an input.txt in the format shown in samples/
 * run `make all` followed by `make run` to solve the puzzle
 */

#include "src/utils.h"

#include "src/Sudoku.h"
#include "src/SudokuReader.h"

#include <iostream>

using namespace std;

int main() {
    
    
    Sudoku S = Sudoku("input/sample.csv");
    S.showProblem();
    S.solve();
    S.showSolution();
    S.writeSolutionToFile();


    return 0;
}
