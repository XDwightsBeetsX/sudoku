# Project Structure

## Folder Structure

```shell
sudoku
│
│   .gitignore
│   LICENSE
│   main.cpp
│   makefile
│   README.md
│
├───bin
│       sudoku_solver.exe
│       *.o
│
├───input
│       sample.csv
│
├───output
│       sample-out.csv
│
└───src
        Sudoku.cpp
        Sudoku.h
        SudokuReader.cpp
        SudokuReader.h
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
        Sudoku <|-- SudokuReader
        Sudoku <|-- SudokuWriter
        Sudoku <|-- utils

        class Sudoku {
            -string InputFilename
            -string OutputFilename
            -SudokuReader
            -SudokuWriter
            -vector<vector<int>> Problem
            -vector<vector<int>> Solution
            -bool recursiveSolve()
            -void printSudoku()
            -bool isEmptyCell()
            -bool isValid()
            -bool isValidRow()
            -bool isValidCol()
            -bool isValidSquare()
            -vector<int> getNextRowAndCol()
            
            +Sudoku(string inputFilename)
            ~Sudoku()
            +void showProblem()
            +void showSolution()
            +void writeSolutionToFile()
            +bool solve()
        }

        class SudokuReader {
            -string InputFilename
            +SudokuReader()
            +SudokuReader(string inputFilename)
            +vector<vector<int>> readProblem()
        }

        class SudokuWriter {
            -string OutputFilename
            +SudokuWriter()
            +void writeToFile(vector<vector<int>> sudoku)
        }

        class utils {
            +vector<string> split(string ipnutString, string delimiter)
        }
```

> *Arrows point towards the highest level class*
>
> *[Documentation](../docs/) is subject to change and may nto be up-to-date*
