#include<bits/stdc++.h>
using namespace std;

template <class T>
void sxTang(T *a, int size){
	for(int i = 0; i < size - 1; i++){
		for(int j = i + 1; j < size; j++){
			if(a[i] > a[j]) swap(a[i], a[j]);
		}
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
int main(){
	int a[] = {2, 3, 9, 5, 7}, sizea = 5;
	double b[] = {1.2, 1.3, 5.3, 3.4, 5.6}; int sizeb = 5;
	sxTang(a, sizea);
	sxTang(b, sizeb);
	xuat(a, sizea); cout<<endl; xuat(b, sizeb);
	return 0;
}
