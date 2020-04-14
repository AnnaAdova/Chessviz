CXX=gcc

CFLAGS =  -c -Wall -Werror -std=c99

FLAGS  =  -Wall -Werror -std=c99

OBJECTS = build/main.o build/board.o build/rules.o build/movements.o build/black_figure.o build/white_figure.o



.PHONY: clean all bin build default



all: bin build default



default: bin/prog




bin/prog: $(OBJECTS)

	$(CXX) $(FLAGS) $(OBJECTS) -o bin/prog



build/main.o: src/main.c src/rules.h src/movements.h src/white_figure.h src/black_figure.h src/board.h

	$(CXX) $(CFLAGS) src/main.c -o build/main.o 



build/board.o: src/board.c src/board.h

	$(CXX) $(CFLAGS) src/board.c -o build/board.o



build/movements.o: src/movements.c src/movements.h src/macro.h src/rules.h src/black_figure.h src/white_figure.h

	$(CXX) $(CFLAGS) src/movements.c -o build/movements.o



build/rules.o: src/rules.c src/macro.h src/rules.h

	$(CXX) $(CFLAGS) src/rules.c -o build/rules.o


build/black_figure.o: src/black_figure.c src/black_figure.h src/macro.h

	$(CXX) $(CFLAGS) src/black_figure.c -o build/black_figure.o


build/white_figure.o: src/white_figure.c src/white_figure.h src/macro.h

	$(CXX) $(CFLAGS) src/white_figure.c -o build/white_figure.o


build:

	mkdir -p build

bin:

	mkdir -p bin 

clean:

	-rm -rf build bin
