CC = clang++
CFLAGS = -std=c++11

SRC = src/board.cpp src/moveutils.cpp 
OBJ = $(SRC:.cpp=.o)

all: main test

main: $(OBJ) src/main.o
	$(CC) $(CFLAGS) -g $^ -o bin/$@

test: $(OBJ) src/test.o
	$(CC) $(CFLAGS) -g $^ -o bin/$@

src/%.o: src/%.cpp
	$(CC) $(CFLAGS) -c -g $< -o $@

clean:
	rm -f bin/* src/*.o
