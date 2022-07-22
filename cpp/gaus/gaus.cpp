#include "../matrix.hpp"
#include "gaus.h"
#include <string>
#include <regex>
#include <ctype.h>

const std::string inp = "../gaus/input.txt";
const std::string gold = "../gaus/golden.txt";


bool isNumber(std::string line){
	char* p;
	strtol(line.c_str(), &p, 10);
	return *p == 0;
}


bool validate(std::string file){
        std::ifstream input(file);
        std::string line;
        std::regex p("([0-9]{1}) ([0-9]{1})");
        std::smatch m;
        std::regex l("(\\w+)");
        std::smatch c;
        std::string temp;
        int iter;
        if(!input.good()) {
                input.close();
                return false;
        }
        if (input.peek() == std::ifstream::traits_type::eof()){
                input.close();
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
					std::cerr<<"\nMatrix item not a Number\n";
                                        input.close();
                                        return false;
                                }
                        }
                } else {
			std::cerr << "Matrix dimensions are incorrect!"<< std::endl;
                        input.close();
                        return false;
                }
            }
            else if (regex_search(line,c,l)) {
                std::cerr << "Matrix size an invalid entry not Number!"<< std::endl;
                input.close();
                return false;
            }
        }
        input.close();
        return true;
}

void test()
{
        std::ifstream input(inp);
        std::ifstream golden(gold);
        std::ofstream exit("exit.txt");
        std::ofstream result("result.txt");
        int a,b;
        int count = 0;
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

int main()
{
        if(validate(inp)){
		test();
	}
	return 0;
}
