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

