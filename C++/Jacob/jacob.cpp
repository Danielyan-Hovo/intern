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
bool applicable(float a[50][51], int n){
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



void print(int iter, float values[], int n){
	cout<<"iter "<<iter<<": ";
	for(int i=0; i<n; i++)
		cout<<"value["<<i+1<<"]="<<values[i]<<" ";
	cout<<endl;
}

void findValues(float a[50][51], int maxI, float old[], int n){
	int i,j,k, iter;
	float sum=0;
	float values_new[n];
	for(iter=1; iter <=maxI; iter++){
		for(i=0;i<n;i++){
			sum=0;
			for(j=0;j<n;j++){
				if(i!=j)
					sum+=a[i][j]*old[j];
			}
			values_new[i]=(a[i][n]-sum)/a[i][i];
		}
		for(k=0; k<n; k++){
			if(fabs(old[k]-values_new[k])<EPSILION)
				continue;
			else{
				flag = 1;
				break;
			}
		}
		if(flag=0){
			print(iter, values_new, n);
			return;
		}
		flag = 0;
		print(iter, values_new, n);
		for(k=0; k<n; k++)
			old[k]=values_new[k];
	}
	print(iter, values_new, n);
}

int jacobi(){
		int i,j,k,x,y,maxI,n;
		float ratio;
		cout<<"Enter no of Unknowns\n";
		cin>>n;
		cout<<"Enter no. of iters\n";
		cin>>maxI;
		float a[50][51];
		float values[50];;

		cout<<"Enter the Augmented Matrix\n";
		for(int i=0;i<n;i++){
			for(int j=0;j<n+1; j++)
				cin>>a[i][j];
		}

		if(!applicable(a,n)){
			cout<<"\nJacobi Method can`t be applied\n";
			return 0;
		}
		cout<<"\nJacobi Method is applicable\n\n";
		for(int i=0; i<n; i++)
			values[i]=0;
		findValues(a, maxI,values, n);
		return 0;
}

int main(){
	jacobi();
}
