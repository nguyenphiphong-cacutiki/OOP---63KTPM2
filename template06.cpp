#include<bits/stdc++.h>
using namespace std;
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
	int a[100], sizea;
	cout<<"Nhap so phan tu mang nguyen: "; cin>>sizea;
	cout<<"Nhap phan tu:\n";
	for(int i = 0; i < sizea; i++){
		cin>>a[i];
	}
	cout<<"Trung binh cong cua mang nguyen: "<<tinhAVG(a, sizea);
	
	
	double b[100]; int sizeb;
	cout<<"\nNhap so phan tu mang double: "; cin>>sizeb;
	cout<<"Nhap phan tu:\n";
	for(int i = 0; i < sizeb; i++){
		cin>>b[i];
	}
	cout<<"Trung binh cong cua mang double: "<<tinhAVG(b, sizeb);
	return 0;
}
