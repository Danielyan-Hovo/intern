#include <fstream>
#include <iostream>
#include "linear.h"

void test_linear(){
        std::ifstream infile;
        std::ofstream exitfile;
        std::ifstream golden;
        std::ofstream result;
        result.open("resultLinear.txt");
        golden.open("goldenLinear.txt");
        exitfile.open("exitLinear.txt");
        infile.open("inputLinear.txt");
        float a,b;
        if(!infile){
                exitfile<<"ERROR from inputLinear.txt"<<std::endl;
        }
        else {
                while(infile>>a>>b){
                        exitfile<<linear(a,b)<<std::endl;
                }
                exitfile.close();
                std::ifstream exitfile;
                exitfile.open("exitLinear.txt");
                float c,d;
                int number = 0;
                int procent = 100;
                while(golden>>c && exitfile>>d){
                        number++;
                        if(c == d) result<<c<<"\t"<<d<<"\t test "<<number<<" passed!"<<std::endl;
                        else{
                                result<<c<<"\t"<<d<<"\ttest "<<number<<" failed!"<<std::endl;
                                procent -=10;
                        }
                }
                if(procent>=50) result<<std::endl<<"Tests passed Succesfully:"<<std::endl<<"Tests Result:  "<<procent<<"%";
        }
        golden.close();
        result.close();
        exitfile.close();
        infile.close();
        std::cout<<"run linear"<<std::endl;
}

int main(){
        test_linear();
        return 0;
}
