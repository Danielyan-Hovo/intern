#include "matrix.h"

Matrix::Matrix( const Matrix& input_matrix )
{
    row = input_matrix.row;
    column = input_matrix.column;
	allocate();
	for (int i = 0; i < row; i++) {
                for (int j = 0; j < column; j++) {
                        matrix[i][j] = input_matrix.matrix[i][j];
                }
        }
}

Matrix::Matrix(int n,int m, float** a)
{
        row = n;
        column = m;
        allocate();
        for (int i = 0; i < row; i++) {
                for (int j = 0; j < column; j++) {
                        matrix[i][j] = a[i][j];
                }
        }
}

void Matrix::allocate()
{
        matrix = new float* [row];
        for (int i = 0; i < row; i++) {
                matrix[i] = new float[column];
        }
}


Matrix::Matrix(int r, int c)
{
      row = r;
      column = c;
      allocate();
	float** matrix = new float*[row];
	for(int i = 0; i < row; i++) {
                matrix[i] = new float[column];
        }
    	for(int i = 0; i < row; i++) {
                for(int j = 0; j < column; j++) {
                matrix[i][j] = 0;
                }
    	}
}

Matrix::~Matrix()
{
    delete_matrix(matrix);
}

float** Matrix::copy_matrix()
{
    float** matrix_copy = new float*[row];
    for (int i = 0; i < row; i++) {
        matrix_copy[i] = new float[column];
    }
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < column; ++j) {
            matrix_copy[i][j] = matrix[i][j];
        }
    }
    return matrix_copy;
}

void Matrix::delete_matrix(float** del_matrix)
{
    for (int i = 0; i < row; i++) {
        delete[] del_matrix[i];
        del_matrix[i] = nullptr;
    }
    delete[] del_matrix;
    del_matrix = nullptr;
}



float** Matrix::diagonal()
{
        float** a = copy_matrix();
        int n = row;
        for (int i=0;i<n;i++) {
                for (int k=i+1;k<n;k++) {
                        if (abs(a[i][i])<abs(a[k][i])) {
                                for (int j=0;j<=n;j++) {
                                        float temp=a[i][j];
                                        a[i][j]=a[k][j];
                                        a[k][j]=temp;
                                }
                        }
                }
        }
        for (int i=0;i<n-1;i++) {
                for (int k=i+1;k<n;k++) {
                        float t=a[k][i]/a[i][i];
                        for (int j=0;j<=n;j++) {
                                a[k][j]=a[k][j]-t*a[i][j];
                        }
                }
        }
        return a;
}

float Matrix::operator()( int i, int j )
{
    return matrix[i][j];
}


std::istream& operator>> (std::istream& s, Matrix& mat)
{
	for (int i = 0; i < mat.row; i++) {
		for (int j=0; j<mat.column; j++) {
			s >> mat.matrix[i][j];
		}
	}
	return s;
}

std::ostream& operator<< (std::ostream& s, const Matrix& mat)
{
	for (int i = 0; i < mat.row; i++) {
		for (int j = 0; j < mat.column; j++) {
			s << mat.matrix[i][j] << " ";
		}
		s << std::endl;
	}
	return s;
}

std::ifstream& operator>> (std::ifstream& fs, Matrix& mat)
{
	for (int i = 0; i < mat.row; i++) {
		for (int j =0;j<mat.column;j++) {
			fs >> mat.matrix[i][j];
		}
	}
	return fs;
}

std::ofstream& operator<< (std::ofstream& fs, const Matrix& mat)
{
        for (int i = 0; i < mat.row; i++) {
                for (int j = 0; j < mat.column; j++) {
				fs << mat.matrix[i][j] << " ";
			}
		fs << std::endl;
	}
	return fs;
}

