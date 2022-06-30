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
	exitfile.open("exitGcd.txt");
	infile.open("inputGcd.txt");
	float a,b;
	while(infile>>a>>b){
		//std::cout<<a<<"  "<<b<<std::endl;
		exitfile<<gcd(a,b)<<std::endl;
	}
	exitfile.close();
	infile.close();
	std::cout<<gcd(24,64)<<std::endl;
	return 0;
}
