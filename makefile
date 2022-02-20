# compile all files and make executable bin/sudoku_solver.exe
all: utils rules reader writer generator sudoku main
	g++ bin/*.o -o bin/sudoku.exe

utils:
	g++ src/utils.cpp -c -o bin/utils.o

rules:
	g++ src/SudokuRules.cpp -c -o bin/SudokuRules.o

reader:
	g++ src/SudokuReader.cpp -c -o bin/SudokuReader.o

writer:
	g++ src/SudokuWriter.cpp -c -o bin/SudokuWriter.o

generator:
	g++ src/SudokuGenerator.cpp -c -o bin/SudokuGenerator.o

sudoku:
	g++ src/SudokuSolver.cpp -c -o bin/SudokuSolver.o

main:
	g++ main.cpp -c -o bin/main.o


# quickly run the program
run:
	./bin/sudoku.exe


# remove all compiled object files
clean:
	rm bin/*.o
	echo "removed all object files. (executable remains)"


# remove all compiled files and the generated executable
wipe:
	rm bin/*
	echo "removed all object files and executable"
