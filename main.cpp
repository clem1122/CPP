#include "matrix.h"

//pthread_t t[8];



int main(){
	/*for (int i = 0; i < 8; i++) {
		pthread_create(&t[i], NULL, start, param)
	
	}*/
	
	Matrix A = Matrix(2);
	Matrix B = Matrix(2);
	Matrix C = A * B;
	A.print();
	B.print();
	C.print();
	return 0;
}
