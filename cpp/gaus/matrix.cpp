#include "../matrix.hpp"
#include <iomanip>


float* gaus(Matrix &matrix){
	float** a = matrix.diagonal();
	int n = matrix.row;
	float* x= new float[10];

	for (int i=n-1;i>=0;i--){
        	x[i]=a[i][n];
        	for (int j=i+1;j<n;j++)
            		if (j!=i)
                		x[i]=x[i]-a[i][j]*x[j];
                if(a[i][i] == 0){
                        x[i] = 0;
                        break;
                }
        	x[i]=x[i]/a[i][i];
	}
        return x;
}

float* jacobi(Matrix &matrix){
        float** mat = matrix.copy_matrix();
	int n = matrix.row;
        float curr[n] = {0};
        float* x = new float[10];
        float prev[n] = {0};
	float maxi = 0;
        int iter = 0;
        bool for_exit = true;
        bool flag = false;
	int count =100;
        while (count--){
                for (int i = 0; i < n; i++){
                        curr[i] = mat[i][n];
                        for (int j = 0; j < n; j++){
                                if (j != i) {
                                        curr[i] -= prev[j]*mat[i][j];
                                }
                                else {
                                        continue;
                                }
                        }
                        curr[i] /= mat[i][i];
                }
                iter++;
                for (int i = 0; i < n; i++)    {
                        maxi = curr[i] - prev [i];
                        prev[i] = curr[i];
                }
        }
	for(int i=0;i<n;i++){
                if(flag){
                        x[i] = 0;
                } else{
                        x[i] = prev[i];
                }
	}
        return x;
}





int main(){
        float eps;
	std::ifstream input("input.txt", std::ios::in);
        int a,b;
        int count=0;
        while(!input.eof()){
                input>>a>>b;
                Matrix matrix(a,b);
                input>>matrix;
                std::cout<<"\n"<<matrix;
                float* x = gaus(matrix);
			float* y = jacobi(matrix);
                for(int i=0;i<a;i++){
                        std::cout<<"X"<<i+1<<" = "<<x[i]<<"\t\t";
                }
                std::cout<<"\n";
                eps = std::abs(x[0]-y[0]);
                for(int i=0;i<a;i++){
                        if(std::abs(x[i]-y[i])>eps)
                                eps = std::abs(x[i]- y[i]);
                        if(eps>0.5){
                                std::cout<<"There is no solution according to the Jacobi method\n";
                                break;
                        } else{
                                 std::cout<<"X"<<i+1<<" = "<<y[i]<<"\t\t";
                        }
                }
                count++;
                if(eps == 0){
                        std::cout<<"\nTest "<<count<<" accuracy is 100%\n";
                        continue;
                }
                if(eps<1){
                        std::cout<<std::setprecision(10);
                        std::cout<<"\nTest "<<count<<" accuracy is "<<eps<<"\n\n";
                }
        }
	input.close();
	return 0;
}
