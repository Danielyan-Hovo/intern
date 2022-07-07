#include<iostream>
#include<iomanip>
#include <fstream>
#include <string>
using namespace std;

void gaus(ifstream &input, ofstream &output, ofstream &exit){
char var[] = {'x','y','z','p','q','m','n'};
    int n,i,j,k;
	output.precision(4);
 	output.setf(ios::fixed);
	input>>n;
    float a[n][n+1],x[n];
    for (i=0;i<n;i++)
        for (j=0;j<=n;j++)
					input>>a[i][j];
    for (i=0;i<n;i++)
        for (k=i+1;k<n;k++)
            if (abs(a[i][i])<abs(a[k][i]))
                for (j=0;j<=n;j++)
                {
                    double temp=a[i][j];
                    a[i][j]=a[k][j];
                    a[k][j]=temp;
                }
    output<<"Matricy texapoxutyunneric heto\n";
    for (i=0;i<n;i++)
    {
        for (j=0;j<=n;j++)
            output<<a[i][j]<<setw(16);
        output<<"\n";
    }
    for (i=0;i<n-1;i++)
        for (k=i+1;k<n;k++)
            {
                double t=a[k][i]/a[i][i];
                for (j=0;j<=n;j++)
                    a[k][j]=a[k][j]-t*a[i][j];
            }

    output<<"\n\nMatricy Gausyan tesqy tarakan gorcoxutyunneric heto:\n";
    for (i=0;i<n;i++)
    {
        for (j=0;j<=n;j++)
            output<<a[i][j]<<setw(16);
        output<<"\n";
    }
    for (i=n-1;i>=0;i--)
    {
        x[i]=a[i][n];
        for (j=i+1;j<n;j++)
            if (j!=i)
                x[i]=x[i]-a[i][j]*x[j];
        x[i]=x[i]/a[i][i];
    }
    output<<"\nPopoxakanneri arjeqnern en:\n";
    for (i=0;i<n;i++){
        output<<var[i]<<" = "<<x[i]<<endl;
        exit<<var[i]<<" = "<<x[i]<<endl;
    }
  exit<<'~'<<endl;      
	output<<'~'<<endl;
}

void test_gaus(){
	ifstream input;
	ofstream output;
	ofstream exit;
	input.open("input.txt");
	output.open("output.txt");
	exit.open("exit.txt");
	gaus(input,output,exit);
	gaus(input,output,exit);
	gaus(input, output, exit);
	gaus(input, output, exit);
	input.close();
	output.close();
	exit.close();

	ofstream result;
	ifstream exit1;
	exit1.open("exit.txt");
	ifstream golden;
	golden.open("golden.txt");
	result.open("result.txt");

	bool test = true;
	string e,g;
	int i = 1;

	string ee,gg;
	while(getline(exit1,e) && getline(golden,g)){
		ee = e;
		gg = g;
		if(gg!=ee){
			result<<"Test "<<i<<" Failed!!!"<<endl;
			test = false;
		}
		else if(gg==ee && test && gg=="~"){
			result<<"Test "<<i<<" Passed <3"<<endl;
			i++;
			test = true;
			continue;
		}
		if(gg=="~"){
			test = true;
			i++;
		}
	}

	exit.close();
	golden.close();
	result.close();
}

int main()
{
    test_gaus();
    return 0;
}
