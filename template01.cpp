#include<bits/stdc++.h>
using namespace std;

// ham nhap
template <typename T>
void nhap(T *a, int &size){
	cout<<"Nhap so phan tu: "; cin>>size;

	for(int i = 0; i < size; i++){
		cout<<"Phan tu "<<i+1<<": "; cin>>a[i];
	}
}

// ham xuat
template <typename T>
void xuat(const T *a, const int &size){
	for(int i = 0; i < size-1; i++){
		cout<<a[i]<<" - ";
	}
	cout<<a[size - 1];
}

// tinh trung binh cong
template <typename T>
float tinhAVG(T *a, int size){
	float tb = 0;
	for(int i = 0; i < size; i++){
		tb += a[i];
	}
	return tb/size;
}

int main(){
	float a[100]; int size1;
	int x[100]; int size2;
	cout<<"Nhap mang so thuc: \n";
	nhap(a, size1);
	cout<<"Nhap mang so nguyen: \n";
	nhap(x, size2);
	cout<<endl<<"Mang 1: \n";
	xuat(a, size1);
	cout<<"\ntrung binh cong mang 1: "<<tinhAVG(a, size1);
	cout<<endl<<"Mang 2: \n";
	xuat(x, size2);
	cout<<"\ntrung binh cong mang 2: "<<tinhAVG(x, size2);
	
	return 0;
}
