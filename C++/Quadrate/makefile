TARGET = quadrate
CC = g++

SRC = $(wildcard *.cpp)
OBJ = $(patsubst %.cpp, %.o, $(SRC))
CXXFLAGS = -std=c++17


all: $(TARGET) 

$(TARGET): $(OBJ)
	        $(CC) $(CXXFLAGS) $(OBJ) -o $(TARGET)

%.o : %.cpp
	        $(CC) $(CXXFLAGS)  -c $< -o $@

run:
	        ./$(TARGET)

clean:
	        rm $(TARGET) *.o
