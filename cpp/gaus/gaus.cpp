#include "../matrix.hpp"
#include "gaus.h"
#include <string>
#include <regex>

const std::string inp = "../gaus/input.txt";
const std::string gold = "../gaus/golden.txt";

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
        for (int lineNum = 1; getline(input, line);lineNum++){
            if (regex_search(line, m, p) && line.length()<6){
                std::cout << std::endl;
                if(std::stoi(m.str(1))+1 == std::stoi(m.str(2))){
                        int row = std::stoi(m.str(1));
                        int column = std::stoi(m.str(2));
                        iter = column*row;
                        std::cout<<"\n"<<row<<"\t"<<column<<"\n";
                        while (iter--) {
                                input>>temp;
                                std::cout<<temp<<" ";
                                if (!std::stoi(temp)) {
                                        input.close();
                                        return false;
                                }
                                std::cout<<"\n";
                        }
                } else {
                        input.close();
                        return false;
                }
            }
            else if (regex_search(line,c,l)) {
                std::cerr << "There's an invalid entry not Number!" << std::endl;
                //input.close();
                //return false;
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
                                std::cout<<x[i]<<"\t"<<y[i]<<std::endl;
                                result<<"Test "<<count<<" Failed! your result: "<<x[i]<<"  expected result: "<<y[1]<<"\n";
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
	//test();
        std::cout<<std::endl<<validate(inp)<<std::endl;
	return 0;
}
