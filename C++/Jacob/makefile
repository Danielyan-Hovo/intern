CC = g++
Input = input.txt
Output = output.txt
SRC = $(wildcard *.cpp)
OBJ = $(patsubst %.cpp, %.o, $(SRC))
CXXFLAGS = -std=c++17



all: jacobi #testJacobi

jacobi: jacobi.o
				@$(CC) $(CXXFLAGS) jacobi.o -o jacobi

#testJacobi: testJacobi.o
#				@$(CC) $(CXXFLAGS) testJacobi.o -o testJacobi

jacobi.o : jacobi.cpp
				@$(CC) $(CXXFLAGS)  -c $< -o $@

#testJacobi.o : testJacobi.cpp
#				@$(CC) $(CXXFLAGS)  -c $< -o $@

run:
				@./jacobi<$(Input)>$(Output)
				@echo "Running..."

test:
				@./testJacobi
				@echo "Testing..."

clean:
				@rm ./jacobi *.o #./testJacobi *.o
				@echo "Cleaning..."

