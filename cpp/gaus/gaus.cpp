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

void test(){
	float eps;
        std::ofstream exit("exit.txt");
        std::ifstream input("input.txt", std::ios::in);
        std::ofstream result("result.txt");
        std::ifstream golden("golden.txt");
        int a,b;
        int count=0;
        while(true){
          	input>>a>>b;
		if(input.eof())
			break;
                Matrix matrix(a,b);
                input>>matrix;
                std::cout<<"\n"<<matrix;
                float* x = new float[a];
                for(int i=0;i<a;i++){
                        golden>>x[i];
                }
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
                                exit<<"There is no solution according to the Jacobi method";
                                break;
                        } else{
                                 exit<<"X"<<i+1<<" = "<<y[i]<<"\t\t";
                        }
                }
                exit<<std::endl;
                count++;
                if(eps < 0.000001){
                        result<<"Test "<<count<<" accuracy is 100%\n";
                        continue;
                }else if(eps<1){
                        result<<"Test "<<count<<" accuracy is "<<eps<<"\n";
                } else {
                        result<<"Test "<<count<<" There is no solution according to the Jacobi method\n";
                }
        }
        result.close();
        exit.close();
        input.close();
        golden.close();


}

int main(){
	test();
	return 0;
}
