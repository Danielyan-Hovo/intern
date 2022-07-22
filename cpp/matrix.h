#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>
#include <fstream>

class Matrix
{
public:
    int row;
    int column;
    float** matrix;

public:
    Matrix(int r, int c);
    Matrix(int, int,float**);
    Matrix( const Matrix&);
    ~Matrix();
    void delete_matrix(float** del_matric);
    float** copy_matrix();
    float** diagonal();
    void allocate();
    float operator()( int i, int j );
    friend std::istream& operator>> (std::istream&, const Matrix&);
    friend std::ostream& operator<< (std::ostream&, const Matrix&);

    friend std::ifstream& operator >> (std::ifstream&, const Matrix&);
    friend std::ofstream& operator << (std::ofstream&, const Matrix&);

};

#endif
