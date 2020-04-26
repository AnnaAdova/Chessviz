CXX=gcc

CFLAGS =  -c -Wall -Werror -std=c99

FLAGS  =  -Wall -Werror -std=c99

OBJECTS = build/main.o build/board.o build/rules.o build/movements.o build/figure.o



.PHONY: clean all bin build default



all: bin build default



default: bin/prog




bin/prog: $(OBJECTS)

	$(CXX) $(FLAGS) $(OBJECTS) -o bin/prog



build/main.o: src/main.c 

	$(CXX) $(CFLAGS) src/main.c -o build/main.o 



build/board.o: src/board.c 

	$(CXX) $(CFLAGS) src/board.c -o build/board.o



build/movements.o: src/movements.c 

	$(CXX) $(CFLAGS) src/movements.c -o build/movements.o



build/rules.o: src/rules.c 

	$(CXX) $(CFLAGS) src/rules.c -o build/rules.o


build/figure.o: src/figure.c 

	$(CXX) $(CFLAGS) src/figure.c -o build/figure.o


build:

	mkdir -p build

bin:

	mkdir -p bin 

clean:

	-rm -rf build bin
