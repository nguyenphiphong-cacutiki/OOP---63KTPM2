#include<bits/stdc++.h>

using namespace std;

class DT{
	private:
		int data[101] = {0};
	public:
		DT(int heSoBac0);
		DT(vector<int> daThuc);
		friend istream & operator >>(istream &in, DT &dt){
			cout<<"Nhap tung he so va bac tuong ung cua so hang ay, nhap bac = -1 de ket thuc!!!";
			int bac = -1;
			do{
				int heSo;
				cout<<"\n\tHe so: "; in>>heSo;
				cout<<"\tBac cua so hang: "; in>>bac;
				if(bac != -1)
					dt.data[bac] += heSo;
			}while(bac != -1);	
			return in;
		}
		friend ostream & operator <<(ostream &out,const DT &dt){
			out<<"f(x) = ";
			bool laPhanTuSau = false;
			for(int i = 100; i >= 0; i--){
				if(dt.data[i] != 0){
					if(!laPhanTuSau){
						laPhanTuSau = true;
					}else{
						out<<" + ";
					}
					if(i > 1)
						out<<dt.data[i]<<" * x^"<<i;
					else if(i == 1)
						out<<dt.data[i]<<" * x";
					else
						out<<dt.data[i];
				}
			}
			return out;
		}
		DT operator +(const DT &dt);
		DT operator -(const DT &dt);
		void getData(int _data[100]);
		void setData(int _data[100]);
		long tinhGiaTri(int x);
};
// dinh nghia class da thuc
DT::DT(int heSo){
	data[0] = heSo;
}
DT::DT(vector<int> daThuc){
			for(int i = 0; i < daThuc.size(); i++){
				data[i] = daThuc.at(i);
			}
}
void DT::getData(int _data[100]){
	for(int i = 0; i <= 100; i++){
		data[i] = _data[i];
	}
}
void DT::setData(int _data[100]){
	for(int i = 0; i <= 100; i++){
		_data[i] = data[i];
	}
}
DT DT::operator +(const DT &dt){
	DT kq(0);
	for(int i = 0 ;i < 100; i++){
		kq.data[i] = this->data[i] + dt.data[i];
	}
	return kq;
}
DT DT::operator -(const DT &dt){
	DT kq(0);
	for(int i = 0 ;i < 100; i++){
		kq.data[i] = this->data[i] - dt.data[i];
	}
	return kq;
}
long DT::tinhGiaTri(int x){
	long kq = 0;
	for(int i = 0; i < 100; i++){
		kq += data[i] * pow(x, i);
	}
	return kq;
	
}

int main(){
	DT dt1(0), dt2(0);
	cout<<"Nhap da thuc 1: \n"; cin>>dt1;
	cout<<"Da thuc 1: "<<dt1;
	cout<<"\nNhap da thuc 2: \n"; cin>>dt2;
	cout<<"Da thuc 2: "<<dt2;
	
	cout<<"\nTong 2 da thuc: "<<dt1 + dt2;
	cout<<"\nHieu 2 da thuc: "<<dt1 - dt2;
	int x;
	cout<<"\nNhap gia tri x: "; cin>>x;
	cout<<"\nGia tri da thuc 1: "; cout<<dt1.tinhGiaTri(x);
	cout<<"\nGia tri da thuc 2: "; cout<<dt2.tinhGiaTri(x);
	cout<<"\nGia tri tong 2 da thuc: "; cout<<(dt1 + dt2).tinhGiaTri(x);
	cout<<"\nGia tri dt1 - dt2: "; cout<<(dt1 - dt2).tinhGiaTri(x);
	
	return 0;
}
