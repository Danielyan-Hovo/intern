#all: gcd run

#gcd: gcd.o
#	g++ gcd.o -o gcd

#gcd.o: gcd.cpp
#	g++ -c gcd.cpp -o gcd.o

#run:
#	./gcd

#clean:
#	rm gcd *.o
TARGET = gcd
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
