#include <iostream>
#include <cstring>
#include <sstream>
#include <fstream>
using namespace std;

void test(){
	ifstream exit;
	ifstream golden;
	exit.open("output.txt");
	golden.open("golden.txt");
	ofstream result;
	result.open("result.txt");
	int i=1;
	string e,g;
	while(getline(exit,e) && getline(golden,g)){
		if(e.compare(g)==0){
			result<<"Test "<<i<<" passed succesfully"<<std::endl;
			i++;
		}
		else{
			result<<"Test "<<i<<" Failed !!!"<<std::endl;
			i++;
		}

	}
	
	exit.close();
	golden.close();
	result.close();
}


int main(){
	test();
	return 0;
}
