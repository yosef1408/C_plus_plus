//
// Created by user on 4/25/2025.
//

#ifndef MATRIX_H
#define MATRIX_H
#include <vector>
#include <ostream>

using  namespace std;


class Matrix {

private:
    vector<vector<double>> matrix;

public:
    //Constructors;
    Matrix(int m, int n):matrix(m,vector<double>(n,0)){};
    Matrix(int m, int n,int val):matrix(m,vector<double>(n,val)){};
    Matrix():matrix(0,vector<double>(0,0));

    //Copy Constructor & Destructor;
    Matrix(const Matrix& other);
    ~Matrix();


    //Operators;
    Matrix& operator()(int row,int col);
    Matrix& operator=(const Matrix& other);
    Matrix operator+(const Matrix& other);


    //Methods;
    int size(int dimension);

    //Other
    friend ostream& operator<<(ostream& os,const Matrix& mx);


};

template <class T, class Func>
int findmin(const T* a , int n , Func compare) {

    int min_index = 0;

    for(int i = 1 ; i < n ;i++) {

        if(compare(a[i], a[min_index] ) == true)
            min_index = i;
    }
    return min_index;
}


#endif //MATRIX_H
