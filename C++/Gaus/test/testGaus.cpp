#include <iostream>
#include "gaus.h"
using namespace std;

void testGaus(){
	int n;
	float** a = new float*[20];
	for(int i=0;i<20;i++)
		a[i] = new float[20];
	input_matrix(a,n);
	a = diagonal(a,n);
	gaus(a,n);
}

int main(){
	testGaus();
	testGaus();
	return 0;
}

