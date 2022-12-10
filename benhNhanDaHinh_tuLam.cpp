#include<bits/stdc++.h>
using namespace std;

class BN{
	private:
		string hoTen, queQuan;
		int namSinh;
	public:
		BN(){
		}
		virtual void nhap();
		virtual void xuat();
		virtual long tienVien();
		int tinhTuoi();
};
class NoiTru: public BN{
	private:
		string phongDT;
		int soNgayNamVien;
	public:
		NoiTru(){
		}
		void nhap();
		void xuat();
		long tienVien();
};
class NgoaiTru: public BN{
	private:
		string diaChi;
		int soNgayDT;
	public:
		NgoaiTru(){
		}
		void nhap();
		void xuat();
		long tienVien();
};
// dinh nghia lop benh nhan
void BN::nhap(){
	cout<<"Nhap ho ten: "; cin.ignore(); getline(cin, hoTen);
	cout<<"Que quan: "; getline(cin, queQuan);
	cout<<"Nam sinh: "; cin>>namSinh;
}
void BN::xuat(){
	cout<<setw(25)<<hoTen<<setw(15)<<queQuan<<setw(5)<<namSinh;
}
int BN::tinhTuoi(){
	return 2022 - namSinh;
}
long BN::tienVien(){
	
}
// dinh nghia lop noi tru
void NoiTru::nhap(){
	BN::nhap();
	cout<<"Phong dieu tri: "; cin.ignore(); getline(cin, phongDT);
	cout<<"So ngay nam vien: "; cin>>soNgayNamVien;
}
void NoiTru::xuat(){
	BN::xuat();
	cout<<setw(5)<<phongDT<<setw(5)<<soNgayNamVien;
}
long NoiTru::tienVien(){
	return soNgayNamVien*300000;
}
// dinh nghia lop ngoai tru
void NgoaiTru::nhap(){
	BN::nhap();
	cout<<"Dia chi: "; cin.ignore(); getline(cin, diaChi);
	cout<<"So ngay dieu tri: "; cin>>soNgayDT;
}
void NgoaiTru::xuat(){
	BN::xuat();
	cout<<setw(20)<<diaChi<<setw(5)<<soNgayDT;
}
long NgoaiTru::tienVien(){
	return soNgayDT*150000;
}
// ham main
int main(){
	vector<BN*> dsBN;
	int soBN, mode;
	cout<<"Nhap so benh nhan: "; cin>>soBN;
	// nhap danh sach
	for(int i = 0; i < soBN; i++){
		mode = -1;
		while(mode != 1 && mode != 2){
			cout<<"Chon (1) de nhap bn noi tru, (2) de nhap benh nhan ngoai tru: "; cin>>mode;
			if(mode == 1 || mode == 2){
				BN *bn;
				if(mode == 1){
					bn = new NoiTru();
				}else{
					bn = new NgoaiTru();
				}
				bn->nhap();
				dsBN.push_back(bn);
			}else{
				cout<<"Lua chon khong hop le, vui long nhap lai!\n";
			}
			
		}
		
	}
	// xuat danh sach
	cout<<"\nDanh sach benh nhan: \n";
	for(int i = 0; i < soBN; i++){
		dsBN.at(i)->xuat();
		cout<<"\t| Tien vien phai tra: "; cout<<dsBN.at(i)->tienVien();
		cout<<endl;
	}
	// sap xep theo tuoi giam dan
	for(int i = 0; i < soBN - 1; i++){
		for(int j = i+1; j < soBN; j++){
			if(dsBN.at(i)->tinhTuoi() < dsBN.at(j)->tinhTuoi())
				 swap(dsBN.at(i), dsBN.at(j));
		}
	}
	// xuat lai danh sach sau sap xep
	cout<<"\nDanh sach benh nhan sau sap xep: \n";
	for(int i = 0; i < soBN; i++){
		dsBN.at(i)->xuat();
		cout<<"\t| Tien vien phai tra: "; cout<<dsBN.at(i)->tienVien();
		cout<<endl;
	}
	// danh sach cac benh nhan tuoi <= 10
	cout<<"\nDanh sach benh nhan co tuoi <= 10:\n";
	for(int i = 0; i < dsBN.size(); i++){
		if(dsBN.at(i)->tinhTuoi() <= 10){
			dsBN.at(i)->xuat();
			cout<<endl;
		}
	}
	// tim max tien vien
	long max = -1;
	for(int i = 0; i < dsBN.size(); i++){
		if(dsBN.at(i)->tienVien() > max) max = dsBN.at(i)->tienVien();
	}
	// in benh nhan co tien vien cao nhat
	cout<<"\nBn co tien vien phi cao nhat:\n";
	for(int i = 0; i < dsBN.size(); i++){
		if(dsBN.at(i)->tienVien() == max){
			dsBN.at(i)->xuat();
			cout<<endl;
		} 
	}
	
	return 0;
}

