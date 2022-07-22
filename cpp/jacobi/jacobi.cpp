#include "../matrix.hpp"
#include <iomanip>
#include "jacobi.h"
#include <string>
#include <regex>

const std::string inp = "../jacobi/input.txt";
const std::string gold = "../jacobi/golden.txt";

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


//The test function calls the jacobi function from the jacobi.h file for the values
//entered from the input.txt file, the returned values of which are first compared
//with the exact values of the golden.txt file, the cases when the system of equations
//does not have a solution according to Jacobi's method are checked, and when it has a solution,
//it is checked is how accurately the test worked and the results are put into the result.txt
//file, after the checks are done the compared values are put into the exit.txt file

void test(){
	float eps;
        std::ofstream exit("exit.txt");
        std::ifstream input(inp, std::ios::in);
        std::ofstream result("result.txt");
        std::ifstream golden(gold);
        int a,b;
        int count=0;
        while(true){
          	input>>a>>b;
		if(input.eof())
			break;
                Matrix matrix(a,b);
                input>>matrix;
                float* x = new float[a];
                for(int i=0;i<a;i++){
                        golden>>x[i];
                }
                float* y = jacobi(matrix);
                eps = std::abs(x[0]-y[0]);
                for(int i=0;i<a;i++){
                        if(std::abs(x[i]-y[i])>eps)
                                eps = std::abs(x[i]- y[i]);
                        if(eps>20){
                                exit<<"There is no solution according to the Jacobi method";
                                break;
                        } else{
                                 exit<<"X"<<i+1<<" = "<<y[i]<<"\t\t";
                        }
                }
                exit<<std::endl;
                count++;
                if(eps < 0.0000008){
                        result<<"Test "<<count<<" accuracy is 100%\n";
                        continue;
                }else if(eps<1){
                        result<<std::fixed<<std::setprecision(7);
                        result<<"Test "<<count<<" accuracy is "<<eps<<"\n";
                } else {
                        result<<"Test "<<count<<" There is no solution according to the Jacobi method\n";
                }
        }
        result.close();
        exit.close();
        input.close();
        golden.close();
}


//in the main function, the condition of the validity of the
//input file is checked and the test function is called for it.

int main(){
	if(validate(inp)){
		test();
	}
	return 0;
}
