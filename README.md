# sudoku

Solve sudoku puzzles in C++

## Usage

1. **Download** the repo

    ```shell
    > git clone https://github.com/XDwightsBeetsX/sudoku
    ```

2. **Edit/Create the `input/input.csv` file** with the `.csv`-formatted sudoku puzzle

    ```c++
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
    ```

3. **Make** the executable

    ```shell
    > make all
    ```

4. **Run** the solver

    ```shell
    > make run
    ```

---

> *see samples in the [input folder](./input/)*
> 
> *[view the code structure](./docs/structure.md)*
>
> *with help from [this](https://www.tutorialspoint.com/sudoku-solver-in-cplusplus) tutorialspoint tutorial*

---
