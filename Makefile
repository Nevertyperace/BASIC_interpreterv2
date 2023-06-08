CC=g++

SRC = $(wildcard *.cpp)
OBJ = $(SRC:.cpp=.o)

all: BASIC

BASIC: $(OBJ)
	 $(CC) $(OBJ) -o BASIC

clean: 
	rm -rf $(OBJ) BASIC


