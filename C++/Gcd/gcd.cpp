#include <fstream>
#include <iostream>
//gcd file

int gcd(int num1,int num2){
	if(num2==0) return num1;
	else return gcd(num2,num1%num2);
}

int main(){
	std::ifstream infile;
	std::ofstream exitfile;
	std::ifstream golden;
	std::ofstream result;
	result.open("resultGcd.txt");
	golden.open("goldenGcd.txt");
	exitfile.open("exitGcd.txt");
	infile.open("inputGcd.txt");
	float a,b;
	if(!infile){
		exitfile<<"ERROR from inputGcd.txt"<<std::endl;
	}
	else {
		while(infile>>a>>b){
			exitfile<<gcd(a,b)<<std::endl;
		}
		exitfile.close();
		std::ifstream exitfile;
		exitfile.open("exitGcd.txt");
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
	std::cout<<"run gcd"<<std::endl;
	return 0;
}
