void input_matrix(float** a,int &n){
	std::cin>>n;
	for (int i=0;i<n;i++)
	      for (int j=0;j<=n;j++)
			std::cin>>a[i][j];
}


float** diagonal(float** &a, int &n){
	for (int i=0;i<n;i++)
        	for (int k=i+1;k<n;k++)
            		if (abs(a[i][i])<abs(a[k][i]))
                		for (int j=0;j<=n;j++) {
                    			float temp=a[i][j];
                    			a[i][j]=a[k][j];
                    			a[k][j]=temp;
                		}
	for (int i=0;i<n-1;i++)
        	for (int k=i+1;k<n;k++) {
                	float t=a[k][i]/a[i][i];
                	for (int j=0;j<=n;j++)
                		a[k][j]=a[k][j]-t*a[i][j];
        	}
	return a;
}


void gaus(float** &a,int &n){
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
