TARGET = linear
CC = g++

SRC = $(wildcard *.cpp)
OBJ = $(patsubst %.cpp, %.o, $(SRC))

all: $(TARGET)

$(TARGET): $(OBJ)
	        @$(CC) $(OBJ) -o $(TARGET)

%.o : %.cpp
	        @$(CC) -c $< -o $@

test:
	        @./$(TARGET)
			@echo "Testing..."

clean:
	        @rm $(TARGET) *.o exit.txt result.txt
			@echo "Cleaning..."
