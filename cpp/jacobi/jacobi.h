float* jacobi(Matrix &matrix)
{
        float curr[matrix.row] = {0};
        float* x = new float[10];
        float prev[matrix.row] = {0};
        float maxi = 0;
        int iter = 0;
        bool flag = false;
        int count =100;
        while (count--){
                for (int i = 0; i < matrix.row; i++) {
                        curr[i] = matrix(i,matrix.row);
                        for (int j = 0; j < matrix.row; j++) {
                                if (j != i) {
                                        curr[i] -= prev[j]*matrix(i,j);
                                } else {
                                        continue;
                                }
                        }
                        curr[i] /= matrix(i,i);
                }
                iter++;
                for (int i = 0; i < matrix.row; i++)    {
                        maxi = curr[i] - prev [i];
                        prev[i] = curr[i];
                }
        }
        for (int i=0;i<matrix.row;i++) {
                if (flag) {
                        x[i] = 0;
                } else {
                        x[i] = prev[i];
                }
        }
        return x;
}

