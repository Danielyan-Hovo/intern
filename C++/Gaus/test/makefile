TARGET = gaus
CC = g++
Input = input.txt
Output = output.txt
SRC = $(wildcard *.cpp)
OBJ = $(patsubst %.cpp, %.o, $(SRC))
CXXFLAGS = -std=c++17

all: $(TARGET) 

$(TARGET): $(OBJ)
	        $(CC) $(CXXFLAGS) $(OBJ) -o $(TARGET)

%.o : %.cpp
	        $(CC) $(CXXFLAGS)  -c $< -o $@

test:
	        ./$(TARGET)<$(Input)>$(Output)

clean:
	        rm $(TARGET) *.o
