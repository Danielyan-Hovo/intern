#include "matrix.h"
using namespace std;

int main(){
	ifstream fin("input.txt");
	Matrix<double> A(3);
	fin>> A;
	cout<< A <<endl;
	Matrix<double> B = A ^ 2;
	cout <<B<<endl;
	Matrix<double> C = A ^-2;
	cout<<C<<endl;
	cout<<B*C;
	fin.close();

	return 0;
}
