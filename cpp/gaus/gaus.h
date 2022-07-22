float* gaus(Matrix &matrix)
{
        float** a = matrix.diagonal();
        float* x= new float[matrix.row];

        for (int i=matrix.row-1;i>=0;i--) {
                x[i]=a[i][matrix.row];
                for (int j=i+1;j<matrix.row;j++) {
                        if (j!=i) {
                                x[i]=x[i]-a[i][j]*x[j];
                        }
                }
                if (a[i][i] == 0) {
                        x[i] = 0;
                        break;
                }
                x[i]=x[i]/a[i][i];
        }
        return x;
}

