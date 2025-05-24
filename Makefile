CC = clang++
CFLAGS = -std=c++11

all: app

app: src/main.cpp
	@$(CC) $(CFLAGS) -g src/main.cpp -o bin/main
