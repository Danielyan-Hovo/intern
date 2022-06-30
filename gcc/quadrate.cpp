#include <iostream>
#include <cmath>
#include <fstream>
//quadrate file


float quadrate (float a, float b, float c){
	float d = b*b-4*a*c;
	if(d>0){
		float x1 = (-b+sqrt(d))/(2*a);
		float x2 = (-b-sqrt(d))/(2*a);
		return x2;
	}
	if(d==0) return -b/(2*a);
	else return -1.1;
}


int main(){
	std::cout<<quadrate(3, 7, 2)<<std::endl;
	return 0;
}
