#include <iostream>
#include <cmath>
using namespace std;

#define EPSILION 0.001

int flag;


//funkcia vory tvyal ankyunagci i-rd texum gtnvox tarri hamar veradarznum e
//nra aj u dzax maseri tareri gumary
float findSum(int i, float a[50][51], int n){
	float sum = 0;
	for(int j = 0; j<n; j++){
		if(i!=j)
			sum +=a[i][j];
	}
	return sum;
}


//funkcian stugum e ardyoq tvyal havasarumneri hamakargi hamar
//tuylatreli e Jacobi metody veradardznum boolean arjeq
bool isMethodApplicable(float a[50][51], int n){
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			if(fabs(a[i][i])>findSum(i,a,n))
				break;
			else
				return false;
		}
	}
	return true;
}



void print(int iteration, float values[], int n){
	cout<<"iteration "<<iteration<<": ";
	for(int i=0; i<n; i++)
		cout<<"value["<<i+1<<"]="<<values[i]<<" ";
	cout<<endl;
}

void findValues(float a[50][51], int maxIterations, float values_old[], int n){
	int i,j,k, iteration;
	float sum=0;
	float values_new[n];
	for(iteration=1; iteration <=maxIterations; iteration++){
		for(i=0;i<n;i++){
			sum=0;
			for(j=0;j<n;j++){
				if(i!=j)
					sum+=a[i][j]*values_old[j];
			}
			values_new[i]=(a[i][n]-sum)/a[i][i];
		}
		for(k=0; k<n; k++){
			if(fabs(values_old[k]-values_new[k])<EPSILION)
				continue;
			else{
				flag = 1;
				break;
			}
		}
		if(flag=0){
			print(iteration, values_new, n);
			return;
		}
		flag = 0;
		print(iteration, values_new, n);
		for(k=0; k<n; k++)
			values_old[k]=values_new[k];
	}
	print(iteration, values_new, n);
}

int jacobi(){
		int i,j,k,x,y,maxIterations,n;
		float ratio;
		cout<<"Enter no of Unknowns\n";
		cin>>n;
		cout<<"Enter no. of iterations\n";
		cin>>maxIterations;
		float a[50][51];
		float values[50];;

		cout<<"Enter the Augmented Matrix\n";
		for(int i=0;i<n;i++){
			for(int j=0;j<n+1; j++)
				cin>>a[i][j];
		}

		if(!isMethodApplicable(a,n)){
			cout<<"\nJacobi Method can`t be applied\n";
			return 0;
		}
		cout<<"\nJacobi Method is applicable\n\n";
		for(int i=0; i<n; i++)
			values[i]=0;
		findValues(a, maxIterations,values, n);
		return 0;
}

<<<<<<< HEAD:C++/Jacobi/jacobi.cpp
int test_jacobi(){


	return 0;
}
=======
>>>>>>> 42a8d8fe11e351ee81fc25d33e0b7e27c2980b56:C++/Jacobi/jacobi.h

int main(){
	jacobi();
}
