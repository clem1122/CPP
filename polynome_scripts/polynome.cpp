#include <iostream>
#include <string.h>

class POLY {
private:
	int degres;
	double *coeffs;

public:
	POLY();
	POLY(int n, double *t);
	~POLY();
	POLY(const POLY &aux);
	void operator=(const POLY &aux);
	void get_deg();
	void print();
};

POLY::POLY() {
	std::cout << "const 1" << std::endl;
	degres = -1;
	coeffs = NULL;
}

POLY::POLY(int n, double *t) {
	std::cout << "const 2" << std::endl;
	if (n <= 0 || t == NULL) {
		degres = -1;
		coeffs = NULL;
	} 
	else {
		degres = n;
		coeffs = new double[n+1];
		memcpy(coeffs, t, (n+1) * sizeof(double));
	}
}

POLY::~POLY(){
	std::cout << "delete" << std::endl;
	if (coeffs != NULL) {
		delete[] coeffs;
	}

}

POLY::POLY(const POLY &aux) {
	if(this != &aux) {
		std::cout << "recopie" << std::endl;
		degres = aux.degres;
		coeffs = new double[1+degres];
		memcpy(coeffs, aux.coeffs, (1+degres)*sizeof(double));
	}
}

void POLY::operator=(const POLY &aux){
	if(this != &aux) {
		if (coeffs != NULL) {
			delete [] coeffs;
		}
		std::cout << "egal" << std::endl;
		degres = aux.degres;
		coeffs = new double[1+degres];
		memcpy(coeffs, aux.coeffs, (1+degres)*sizeof(double));
	}
}

void POLY::get_deg(){
	std::cout << degres << std::endl;
}

void POLY::print(){
	for (int i = 0; i <= degres; ++i) {
        	std::cout << coeffs[i] << "x^" << i;
       		if (i < degres) {
           	std::cout << " + ";
        }
    }
    std::cout << std::endl;
}
	

void toto(POLY &p) {
}

int main(){
	double t[] = {1,2,3};
	POLY p1;
	POLY p2(3,t);
	POLY p3;
	p3 = p2;
	
	p3.get_deg();
		
	return 0;
}
	
	
