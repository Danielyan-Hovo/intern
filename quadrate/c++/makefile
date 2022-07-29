TARGET = quadrate
CC = g++

SRC = $(wildcard *.cpp)
OBJ = $(patsubst %.cpp, %.o, $(SRC))
CXXFLAGS = -std=c++17


all: $(TARGET) 

$(TARGET): $(OBJ)
	        @$(CC) $(CXXFLAGS) $(OBJ) -o $(TARGET)

%.o : %.cpp
	        @$(CC) $(CXXFLAGS)  -c $< -o $@

test:
	        @./$(TARGET)
			@echo "Testing..."

clean:
	        @rm $(TARGET) *.o exit.txt result.txt
			@echo "Cleaning..."
