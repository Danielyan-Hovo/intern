CC = g++
SRC = $(wildcard *.cpp)
OBJ = $(patsubst %.cpp, %.o, $(SRC))
CXXFLAGS = -std=c++17



all: gaus

gaus: gaus.o
	@$(CC) $(CXXFLAGS) gaus.o -o gaus

gaus.o : gaus.cpp
	@$(CC) $(CXXFLAGS)  -c $< -o $@


test:
	@./gaus
	@echo "Testing..."


clean:
	@rm ./gaus  *.o exit.txt result.txt
	@echo "Cleaning..."
