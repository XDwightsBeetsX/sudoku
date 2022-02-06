# Project Structure

## Folder Structure

```shell
main.cpp
src/
| Sudoku.h
| Sudoku.cpp
| SudokuReader.h
| SudokuReader.cpp
| SudokuWriter.h
| SudokuWriter.cpp
bin/
| sudoku_solver.exe
| main.o
| Sudoku.o
| SudokuReader.o
| SudokuWriter.o
input/
| input.csv
output/
| output.csv
docs/
| #docs...
```

## Class Diagram

```mermaid
    classDiagram
        Sudoku <|-- SudokuReader
        Sudoku <|-- SudokuWriter

        class Sudoku {
            -string InputFilename
            +Sudoku(string inputFilename)
            +showProblem()
            +solve()
            +showSolution()
            +writeSolutionToFile()
        }

        class SudokuReader {
            -string InputFilename
            +SudokuReader(string inputFilename)
            +SudokuReader::readProblem()
        }

        class SudokuWriter {
            +SudokuWriter::writeToFile(string outputFilename, int* sudokuArray)
        }
```

> *Arrows point towards the highest level class*
