CC = g++
CFLAGS = -g -I./include

SRC = ./src
INC = ./include
OUT = ./obj

_DEPS = Node.hpp LinkedList.hpp
DEPS = $(patsubst %,$(INC)/%,$(_DEPS))

_OBJ = Node.o LinkedList.o
OBJ = $(patsubst %, $(OUT)/%, $(_OBJ))

linkedlist: $(OUT)/main.o $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

$(OUT)/main.o: main.cpp
	$(CC) -c -o $(OUT)/main.o main.cpp $(CFLAGS)

$(OUT)/%.o: $(SRC)/%.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)
