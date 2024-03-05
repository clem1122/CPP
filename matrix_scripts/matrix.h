class Matrix{
private:
	int N;
	double** M;

public:
	Matrix();
	Matrix(int n);
	Matrix operator*(const Matrix& B)const;
	~Matrix();
	void print();
};


