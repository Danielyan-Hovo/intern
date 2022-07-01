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
	if(!infile){
		exitfile<<"ERROR from inputLinear.txt file"<<std::endl;
	}
	else{
		while(infile>>a>>b){
			exitfile<<linear(a,b)<<std::endl;
		}
	}
	infile.close();
	exitfile.close();
	std::cout<<"run linear"<<std::endl;
	return 0;
}
