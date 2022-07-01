TARGET = linear
CC = g++

SRC = $(wildcard *.cpp)
OBJ = $(patsubst %.cpp, %.o, $(SRC))

all: $(TARGET) run clean

$(TARGET): $(OBJ)
	        $(CC) $(OBJ) -o $(TARGET)

%.o : %.cpp
	        $(CC) -c $< -o $@

run:
	        ./$(TARGET)

clean:
	        rm $(TARGET) *.o
