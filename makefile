# compile all files and make executable bin/sudoku_solver.exe 
all: reader writer sudoku main
	g++ bin/*.o -o bin/sudoku_solver.exe

reader:
	g++ src/SudokuReader.cpp -c -o bin/SudokuReader.o

writer:
	g++ src/SudokuWriter.cpp -c -o bin/SudokuWriter.o

sudoku:
	g++ src/Sudoku.cpp -c -o bin/Sudoku.o

main:
	g++ main.cpp -c -o bin/main.o


# quickly run the program
run:
	./bin/sudoku_solver.exe


# remove all compiled object files
clean:
	rm bin/*.o
	echo "removed all object files. (executable remains)"


# remove all compiled files and the generated executable
wipe:
	rm bin/*
	echo "removed all object files and executable"
