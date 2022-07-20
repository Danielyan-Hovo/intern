#include "matrix.h"


void gaus(Matrix &matrix){
	float** a = matrix.diagonal();
	int n = matrix.row;
	float x[10],sum=0;
	for (int i=n-1;i>=0;i--){
        	x[i]=a[i][n];
        	for (int j=i+1;j<n;j++)
            		if (j!=i)
                		x[i]=x[i]-a[i][j]*x[j];
        	x[i]=x[i]/a[i][i];
	}
    	for (int i=0;i<n;i++)
        	std::cout<<"X"<<i+1<<"="<<x[i]<<"\t\t";
	std::cout<<"\n";
}

void jacobi(Matrix &matrix){
        //float epsilon = 0.00001;
        float** mat = matrix.copy_matrix();
	int n = matrix.row;
        float curr[n] = {0};
        float prev[n] = {0};
	float maxi = 0;
        int iter = 0;
        bool for_exit = true;
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
		//std::cout<<"Iteration"<<iter<<"\t";
                for (int i = 0; i < n; i++)    {
                        maxi = curr[i] - prev [i];
                        //if (std::abs(maxi) <= epsilon){
                        //        count++;
                        //}
                        //if(count >= n){
                        //        for_exit = false;
                        //}
                        //else if(iter > 30){
                        //        for_exit = false;
			//	std::cout<<"\tLucum chuni\n";
			//	break;
                        //}
                        prev[i] = curr[i];
			//std::cout<<prev[i]<<'\t';
                }
		//std::cout<<std::endl;
        }
	for(int i=0;i<n;i++){
		//if(iter<30)
		std::cout<<"X"<<i+1<<"="<<prev[i]<<"\t\t";
	}
	std::cout<<"\n";
}

//////////////////////////////////////////////////////////////////////
int* read_length(std::ifstream &file){
    int r,c;
    file >> r >> c;
    if (file.eof()) {
        return nullptr;
    }
    int row = r;
    int column = c;
    int* length = new int[2];
    length[0] = row;
    length[1] = column;
    return length;
}




int main(){
	std::ifstream input("input.txt", std::ios::in);
	while(!input.eof()){
		int* len = read_length(input);
		if(len == NULL)
			break;
		Matrix matrix(len[0],len[1]);
		matrix.init_from_file(input);
		matrix.print();
		gaus(matrix);
		jacobi(matrix);
	}
	//Matrix matrix(row, column);
	//matrix.init_from_file(input);
	//matrix.print();
	input.close();
	return 0;
}
