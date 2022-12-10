#include <iostream>
using namespace std;

class Matrix{
	private:
		int  m, n;
		int A[100][100];
	public:
		Matrix(){}
		int getM(){
			return m;
		}
		int getN(){
			return n;
		}
		Matrix(int _m, int _n){
			m = _m;
			n = _n;
			for(int i = 0; i < _m; i++){
				for(int j = 0; j < _n; j++){
					A[i][j] = 0;
				}
			}
		}
		void nhap(){
			cout<<"Nhap matrix: \n";
			cout<<"So dong: "; cin>>m;
			cout<<"So cot: "; cin>>n;
			cout<<"Nhap cac phan tu: \n";
			for(int i = 0; i< m; i++){
				for(int j = 0; j < n; j++){
					cin>>A[i][j];
				}
			}
		}
		void xuat(){
			cout<<"In matrix: \n";
			for(int i = 0; i<m; i++){
				for(int j = 0; j<n; j++){
					cout<<A[i][j]<<" ";
				}
				cout<<endl;
			}
		}
		bool isCong(Matrix a){
			if(a.n == n && a.m == m) return true;
			else return false;
			
		}
		Matrix cong(const Matrix & x){			
				Matrix kq(m, n);
					for(int i = 0; i < m; i++){
						for(int j = 0; j < n; j++){
							kq.A[i][j] = A[i][j] + x.A[i][j];
						}
						
					}
				return kq;
		}
		bool isNhan(const Matrix &a){
			if(n == a.m) return true;
			else return false;
		}
		
		friend Matrix multiple(const Matrix &a, const Matrix &b);
		
		~Matrix(){
		}
		
};
		Matrix multiple(const Matrix &a, const Matrix &b){		
			Matrix kq(a.m, b.n);
			for(int i = 0; i<a.m; i++){
				for(int j = 0; j<b.n; j++){
					for(int k = 0; k < a.n ; k++){
						kq.A[i][j] += (a.A[i][k] * b.A[k][j]);
 					}
				}
			}
			return kq;
	}

int main(){
	Matrix a, b;
	a.nhap();
	a.xuat();
	b.nhap();
	b.xuat();
	// tao ma tran tich
	if(a.isNhan(b)){
		Matrix c = multiple(a, b);
		cout<<"Ma tran tich cua a va b: \n";
		c.xuat();
	}
	else{
		cout << "khong the nhan hai ma tran!";	
}
	
	// tao ma tran cong
	
	if(a.isCong(b)){
		Matrix d = a.cong(b);
		cout<<"ma tran tong cua a va b";
		d.xuat();
	}
	else cout << "khong the cong hai ma tran!";

	return 0;
}
