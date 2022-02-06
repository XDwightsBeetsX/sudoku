all: src main
	g++ bin/*.o -o bin/sudoku_solver.exe

src:
	g++ src/*.cpp -c -o bin/src.o

main:
	g++ main.cpp -c -o bin/main.o


# remove all compiled object files
clean:
	rm bin/*.o

# remove all compiled files and the generated executable
wipe:
	rm bin/*
