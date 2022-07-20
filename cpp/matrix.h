#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>
#include <fstream>

class Matrix{
public:
    const int row;
    const int column;
    float** matrix;

public:
    Matrix(const int r, const int c);
    ~Matrix();
    float** init_matrix();
    float** init_from_file(std::ifstream &file);
    void delete_matrix(float** del_matric);
    float** copy_matrix();
    float** diagonal();
    void print();
};

Matrix::Matrix(const int r, const int c)
        : row(r)
          , column(c) {
          matrix = init_matrix();
      }

Matrix::~Matrix(){
    delete_matrix(matrix);
}

float** Matrix::copy_matrix(){
    float** matrix_copy = new float*[row];
    for(int i = 0; i < row; i++) {
        matrix_copy[i] = new float[column];
    }
    for (int i = 0; i < row; ++i)
        for(int j = 0; j < column; ++j)
            matrix_copy[i][j] = matrix[i][j];
    return matrix_copy;
}


float** Matrix::init_matrix(){
    float** matrix = new float*[row];
    for(int i = 0; i < row; i++) {
        matrix[i] = new float[column];
    }
    for(int i = 0; i < row; i++) {
        for(int j = 0; j < column; j++) {
            matrix[i][j] = 0;
            return matrix;
        }
    }
}

float** Matrix::init_from_file(std::ifstream &file){
    float temp = 0;
    for(int i = 0; i < row; i++) {
        for(int j = 0; j < column; j++) {
            file >>temp;
            matrix[i][j] = temp;
        }
    }
}

void Matrix::delete_matrix(float** del_matrix){
    for (int i = 0; i < row; i++) {
        delete[] del_matrix[i];
        del_matrix[i] = nullptr;
    }
    delete[] del_matrix;
    del_matrix = nullptr;
}

void Matrix::print(){
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < column; j++) {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << '\n';
    }
}


float** Matrix::diagonal(){
        float** a = copy_matrix();
        int n = row;
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


#endif
