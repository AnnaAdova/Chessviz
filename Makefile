CXX=gcc

CFLAGS =  -c -Wall -Werror -std=c99

FLAGS  =  -Wall -Werror -std=c99

OBJECTS = build/src/main.o build/src/board.o build/src/rules.o build/src/movements.o build/src/figure.o

OBJECTS_TEST = build/test/main.o build/test/rules.o build/test/figure.o


.PHONY: clean all bin build default test


all: default test


default: bin build bin/key


test: bin build bin/key_test
	bin/key_test


bin/key_test: $(OBJECTS_TEST)
	$(CXX) $(FLAGS) $(OBJECTS_TEST) -o bin/key_test


build/test/main.o: test/main.c
	$(CXX) $(CFLAGS) test/main.c -I thirdparty/ -I src/ -o build/test/main.o


build/test/rules.o: test/test_rules.c
	$(CXX) $(CFLAGS) test/test_rules.c -I thirdparty/ -I src/ -o build/test/rules.o


build/test/figure.o: test/test_figure.c
	$(CXX) $(CFLAGS) test/test_figure.c -I thirdparty/ -I src/ -o build/test/figure.o

bin/key: $(OBJECTS)
	$(CXX) $(FLAGS) $(OBJECTS) -o bin/key


build/src/main.o: src/main.c 
	$(CXX) $(CFLAGS) src/main.c -o build/src/main.o 


build/src/board.o: src/board.c 
	$(CXX) $(CFLAGS) src/board.c -o build/src/board.o


build/src/movements.o: src/movements.c 
	$(CXX) $(CFLAGS) src/movements.c -o build/src/movements.o


build/src/rules.o: src/rules.c 
	$(CXX) $(CFLAGS) src/rules.c -o build/src/rules.o


build/src/figure.o: src/figure.c 
	$(CXX) $(CFLAGS) src/figure.c -o build/src/figure.o


build:
	mkdir -p build/src
	mkdir -p build/test


bin:
	mkdir -p bin 


clean:
	-rm -rf build bin
