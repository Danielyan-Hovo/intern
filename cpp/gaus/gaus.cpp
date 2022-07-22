#include "../matrix.hpp"
#include "gaus.h"
#include <string>
#include <regex>

const std::string inp = "../gaus/input.txt";
const std::string gold = "../gaus/golden.txt";


//The isNumber function is used to validate the input
//file and checks that the input value is a number.

bool isNumber(std::string line){
	char* p;
	strtol(line.c_str(), &p, 10);
	return *p == 0;
}



//The validate function checks the validation of input data.
//This function can generate 5 errors as a result of its operation.
//1. when the file does not exist
//2. when the file is empty
//3. when the matrix size given in the file is incorrect
//4. when the size of the matrix is ​​not numbers
//5. when the matrix values ​​are not numbers.
//The function throws generated errors into the exit.txt file and returns a 
//boolean value depending on whether the input file is valid or not.

bool validate(std::string file){
        std::ifstream input(file);
        std::ofstream exit("exit.txt");
        std::string line, temp;
        std::regex p("([0-9]{1}) ([0-9]{1})");
        std::smatch m;
        std::regex l("(\\w+)");
        std::smatch c;
        int iter;
        if(!input.good()) {
                exit<<"Input file is absent!\n";
                input.close(); exit.close();
                return false;
        }
        if (input.peek() == std::ifstream::traits_type::eof()){
                exit<<"Input file is Empty!\n";
                input.close(); exit.close();
                return false;
        }
        while (getline(input, line)) {
            if (regex_search(line, m, p) && line.length()<6){
                std::cout << std::endl;
                if(std::stoi(m.str(1))+1 == std::stoi(m.str(2))){
                        int row = std::stoi(m.str(1));
                        int column = std::stoi(m.str(2));
                        iter = column*row;
                        while (iter--) {
                                input>>temp;
                                if (!isNumber(temp)) {
					exit<<"Matrix item not a Number\n";
                                        input.close(); exit.close();
                                        return false;
                                }
                        }
                } else {
			exit << "Matrix dimensions are incorrect!"<< std::endl;
                        input.close(); exit.close();
                        return false;
                }
            }
            else if (regex_search(line,c,l)) {
                exit << "Matrix size an invalid entry not Number!"<< std::endl;
                exit.close(); input.close();
                return false;
            }
        }
        input.close(); exit.close();
        return true;
}


//The test function calls the gaus function from the gaus.h file for the values
//input from the input.txt file, whose returned values ​​are compared first
//with the exact values ​​of the golden.txt file, it checks which tests worked
//correctly, and if they worked incorrectly, it indicates that the value is wrong
//and what the value should have been, then the results are placed in result.txt
//file, after performing the checks, the compared values ​​are placed in the exit.txt file

void test()
{
        std::ifstream input(inp);
        std::ifstream golden(gold);
        std::ofstream exit("exit.txt");
        std::ofstream result("result.txt");
        int a,b, count = 0;
        while (!input.eof()) {
                input>>a>>b;
                if (input.eof()) {
                        break;
                }
                Matrix matrix(a,b);
                input>>matrix;
                float* x = gaus(matrix);
                float* y = new float[a];
                count++;
                exit<<std::endl;
                for (int i = 0;i<a;i++) {
                        exit<<"X"<<i+1<<" = "<<x[i]<<"\t";
                        golden>>y[i];
                        if (std::abs(x[i]-y[i])>0.001) {
                                result<<"Test "<<count<<" Failed! your result: X"<<i+1<<"="<<x[i]<<"  expected result: X"<<i+1<<"="<<y[1]<<"\n";
                                break;
                        } else if (i == (a-1) && x[i] == y[i]) {
                                result<<"Test "<<count<<" Passed Succsesfully\n";
                        }
                }
        }
        input.close();
        golden.close();
        exit.close();
        result.close();
}


//in the main function, the condition of the validity of the 
//input file is checked and the test function is called for it.

int main()
{
        if(validate(inp)){
		test();
	}
	return 0;
}
