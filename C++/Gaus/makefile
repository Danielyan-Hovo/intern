CC = g++
Input = input.txt
Output = output.txt
SRC = $(wildcard *.cpp)
OBJ = $(patsubst %.cpp, %.o, $(SRC))
CXXFLAGS = -std=c++17



all: gaus testGaus

gaus: gaus.o
			@$(CC) $(CXXFLAGS) gaus.o -o gaus

testGaus: testGaus.o
			@$(CC) $(CXXFLAGS) testGaus.o -o testGaus

gaus.o : gaus.cpp
			@$(CC) $(CXXFLAGS)  -c $< -o $@

testGaus.o : testGaus.cpp
			@$(CC) $(CXXFLAGS)  -c $< -o $@

run:
		        @./gaus<$(Input)>$(Output)
			@echo "Running..."

test:
			@./testGaus
			@echo "Testing..."

clean:
		        @rm ./gaus ./testGaus *.o
			@echo "Cleaning..."
