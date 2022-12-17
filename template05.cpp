#include<bits/stdc++.h>
using namespace std;

template <class T>
T findMin(T *a, int size){
	T min = a[0];
	for(int i = 0; i < size; i++){
		if(a[i] < min) min = a[i];
	}
	return min;
}
template<class T>
T findMax(T *a, int size){
	T max = a[0];
	for(int i = 0; i < size; i++){
		if(a[i] > max) max = a[i];
	}
	return max;
}
int main(){
	int a[100], sizea;
	cout<<"Nhap so phan tu kieu nguyen: "; cin>>sizea;
	cout<<"Nhap phan tu:\n";
	for(int i = 0; i < sizea; i++){
		cin>>a[i];
	}
	cout<<"Phan tu nho nhat: "<<findMin(a, sizea);
	
	
	double b[100], sizeb;
	cout<<"\nNhap so phan tu kieu thuc: "; cin>>sizeb;
	cout<<"Nhap phan tu:\n";
	for(int i = 0; i < sizeb; i++){
		cin>>b[i];
	}
	cout<<"Phan tu lon nhat: "<<findMax(b, sizeb);
	return 0;
}
