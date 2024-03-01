#include <iostream>
#include <random>
#include"matrix.h"

Matrix::Matrix(int n) {
	std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> distribution(0, 5);
    
	std::cout << "Initialisation" << std::endl;
	N = n;
	M = new double*[N];
	for(int i = 0; i < N; i++){
		M[i] = new double[N];
		for(int j = 0; j < N; j++){
			M[i][j] = distribution(gen);
		}
	}	
}


void Matrix::print(){
    for (int i = 0; i < N; i++) {        
        for (int j = 0; j < N; j++) {
            std::cout << M[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

Matrix Matrix::operator*(const Matrix& B) const {
	int n = N;
	Matrix C = Matrix(n);
    for (int i = 0; i < n; i++) {       
        for (int j = 0; j < n; j++) { 
        	double S = 0;
			for (int k = 0; k < n; k++){
				S += M[i][k] * B.M[k][j];
			} 
			C.M[i][j] = S;
		}
	}

	return C;
}







Matrix::~Matrix(){
	std::cout << "Destructor" << std::endl;
	for (int i = 0; i < N; i++){
		delete[] M[i];
	}
	delete[] M;
}
