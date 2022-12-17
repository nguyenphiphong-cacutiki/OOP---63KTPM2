#include<bits/stdc++.h>
using namespace std;

template <class T>
T findMin(T a, T b){
	return a<b? a:b;
}
int main(){
	int a, b;
	double x, y;
	cout<<"Nhap 2 so int: "; cin>>a; cin>>b;
	cout<<"So nho hon: "<<findMin(a, b);
	
	
	cout<<"\nNhap 2 so double: "; cin>>x; cin>>y;
	cout<<"So nho hon: "<<findMin(x, y);
	return 0;
}
