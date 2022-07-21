CC = g++
SRC = $(wildcard *.cpp)
OBJ = $(patsubst %.cpp, %.o, $(SRC))
CXXFLAGS = -std=c++17



all: jacobi

jacobi: jacobi.o
	@$(CC) $(CXXFLAGS) jacobi.o -o jacobi

jacobi.o : jacobi.cpp
	@$(CC) $(CXXFLAGS)  -c $< -o $@


test:
	@./jacobi
	@echo "Testing..."


clean:
	@rm ./jacobi  *.o exit.txt result.txt
	@echo "Cleaning..."

