# Project Structure

## Folder Structure

```shell
sudoku
│   .gitignore
│   LICENSE
│   main.cpp
│   makefile
│   README.md
│
├───bin
│       sudoku.exe
│       *.o
│
├───docs
│       sample_format.md
│       structure.md
│
├───imgs
│       class_diagram.png
│
├───input
│   │   sample.csv
│   │
│   └───generated
│           gen_puzzle_1.csv
│           gen_puzzle_10.csv
│           gen_puzzle_2.csv
│           gen_puzzle_3.csv
│           gen_puzzle_4.csv
│           gen_puzzle_5.csv
│           gen_puzzle_6.csv
│           gen_puzzle_7.csv
│           gen_puzzle_8.csv
│           gen_puzzle_9.csv
│
├───output
│       sample-out.csv
│
└───src
        SudokuGenerator.cpp
        SudokuGenerator.h
        SudokuReader.cpp
        SudokuReader.h
        SudokuRules.cpp
        SudokuRules.h
        SudokuSolver.cpp
        SudokuSolver.h
        SudokuWriter.cpp
        SudokuWriter.h
        utils.cpp
        utils.h
```

## Class Diagram

### Image for Compatibility

![class diagram](../imgs/class_diagram.png)

### Mermaid Markdown

```mermaid
    classDiagram
        direction LR
        SudokuSolver <|-- SudokuReader
        SudokuSolver <|-- SudokuWriter
        SudokuSolver <|-- utils
        SudokuSolver <|-- SudokuRules
        SudokuGenerator <|-- SudokuRules
        

        class SudokuSolver {
            -string InputFilename
            -string OutputFilename
            -SudokuReader
            -SudokuWriter
            -vector<vector<int>> Problem
            -vector<vector<int>> Solution
            -bool recursiveSolve()
            -void printSudoku(vector<vector<int>> &sudoku)
            -vector<int> getNextRowAndCol()
            
            +SudokuSolver(string inputFilename)
            ~SudokuSolver()
            +void showProblem()
            +void showSolution()
            +void writeSolutionToFile(string outputFilename)
            +bool solve()
        }
        
        class SudokuReader {
            -string InputFilename
            +SudokuReader()
            +SudokuReader(string inputFilename)
            +vector<vector<int>> readProblem()
        }

        class SudokuWriter {
            +static void writeToFile(vector<vector<int>> &sudoku, string &outputFilename)
        }

        class SudokuRules {
            +static bool isValid(vector<vector<int>> &sudoku, int &row, int &col, int &value)
            +static bool isEmptyCell(vector<vector<int>> &sudoku, int &row, int &col)
            +static bool isValidRow(vector<vector<int>> &sudoku, int &row, int &value)
            +static bool isValidCol(vector<vector<int>> &sudoku, int &row, int &value)
            +static bool isValidSquare(vector<vector<int>> &sudoku, int &row, int &col, int &value)
        }

        class SudokuGenerator {
            +void generatePuzzles(int count)
        }

        class utils {
            +vector<string> split(string inputString, string delimiter)
        }
```

> *Arrows point towards the highest level class*
>
> *[Documentation](../docs/) is subject to change and may nto be up-to-date*
>
> *Last updated 2/20/2022*
