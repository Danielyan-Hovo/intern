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

