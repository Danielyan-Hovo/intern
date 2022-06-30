#include <iostream>
#include <fstream>
//linear file

float linear(float num1,float num2){
	if(num1==0) return false;
	else if(num1==0 && num2==0) return true;
	else return num2/num1;
}



int main(){
	std::ifstream infile;
	infile.open("inputLinear.txt");
	std::ofstream exitfile;
	exitfile.open("exitLinear.txt");
	float a,b;
	while(infile>>a>>b){
		exitfile<<linear(a,b)<<std::endl;
	}
	infile.close();
	exitfile.close();
	std::cout<<linear(123.654,456.987)<<std::endl;
	return 0;
}
