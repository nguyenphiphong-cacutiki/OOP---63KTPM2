#include<bits/stdc++.h>
using namespace std;

class NV{
	private:
		string hoTen, ngaySinh;
	protected:
		long luongCB = 1490000;
	public:
		NV(){
		}
		void setLuongCB(long _luongCB);
		virtual void nhap();
		virtual void xuat();
		virtual long tinhLuong();
		string getHoTen();
		bool giongTen(string s);
};
class NVVP:public NV{
	private: 
		int soNgay;
		long troCap = 700000;
	public:
		NVVP(){
		}
		void nhap();
		void xuat();
		long tinhLuong();
		void setTroCap(long _troCap);
		
};
class NVSX:public NV{
	private:
		int soSP;
	public:
		NVSX(){
		}
		void nhap();
		void xuat();
		long tinhLuong();
};
class NVQL:public NV{
	private:
		int heSoCV;
		long thuong = 1000000;
	public:
		NVQL(){
		}
		void nhap();
		void xuat();
		long tinhLuong();
		void setThuong(long _thuong);
};
class DSNV{
	private:
		vector<NV*> ds;
	public:
		DSNV(){
		}
		void nhapDS();
		void xuatDS();
		long long tinhTongLuong();
		DSNV timKiem(string _hoTen);
};

int main(){
	DSNV ds;
	cout<<"Nhap danh sach nhan vien: \n";
	ds.nhapDS();
	cout<<"\nDanh sach vua nhap: \n";
	ds.xuatDS();
	cout<<"\nTong luong cua cong ty la: "<<ds.tinhTongLuong();
	string nameSearch;
	cout<<"\nNhap ten can tim kiem: "; fflush(stdin); getline(cin, nameSearch);
	cout<<"\nCac nhan vien co ten vua nhap la: \n";
	ds.timKiem(nameSearch).xuatDS();
	
	return 0;
}
// dinh nghia lop NV
void NV::setLuongCB(long _luongCB){
	luongCB = _luongCB;
}
void NV::nhap(){
	cout<<"Ho ten: "; fflush(stdin); getline(cin, hoTen);
	cout<<"Ngay sinh: "; fflush(stdin); getline(cin, ngaySinh);
}
void NV::xuat(){
	cout<<hoTen<<"  |  "<<ngaySinh;
}
long NV::tinhLuong(){
	return 0;
}
string NV::getHoTen(){
	return hoTen;
}
bool NV::giongTen(string s){
	if(s.size() != hoTen.size()) return false;
	for(int i = 0; i < s.size(); i++){
		if(hoTen[i] != s[i]) return false;
	}
	return true;
}
// dinh nghia lop NVVP
void NVVP::nhap(){
	NV::nhap();
	cout<<"So ngay lam viec: "; cin>>soNgay;
	cout<<"Tro cap: "; cin>>troCap;
}
void NVVP::xuat(){
	NV::xuat();
	cout<<"  |  so ngay lam viec: "<<soNgay<<"  |  tro cap: "<<troCap<<"  |  luong: "<<tinhLuong();
}
long NVVP::tinhLuong(){
	return luongCB + soNgay*200000 + troCap;
}
void NVVP::setTroCap(long _troCap){
	troCap = _troCap;
}
// dinh nghia lop nhan vien san xuat
void NVSX::nhap(){
	NV::nhap();
	cout<<"Nhap so sp: "; cin>>soSP;
}
void NVSX::xuat(){
	NV::xuat();
	cout<<"  |  so sp: "<<soSP<<"  |  luong: "<<tinhLuong();
}
long NVSX::tinhLuong(){
	return luongCB + soSP*2000;
}
// dinh nghia lop nhan vien quan ly
void NVQL::nhap(){
	NV::nhap();
	cout<<"He so chuc vu: "; cin>>heSoCV; 
	cout<<"Nhap thuong: "; cin>>thuong;
}
void NVQL::xuat(){
	NV::xuat();
	cout<<"  |  he so cv: "<<heSoCV<<"  |  thuong: "<<thuong<<"  |  luong: "<<tinhLuong();
}
long NVQL::tinhLuong(){
	return luongCB * heSoCV + thuong;
}
void NVQL::setThuong(long _thuong){
	thuong = _thuong;
}
// dinh nghia lop danh sach nhan vien
void DSNV::nhapDS(){
	int luaChon = -1;
	NV *tmp;
	do{
		cout<<"Lua chon (1) nhap nvvp, (2) nvsx, (3) nvql, (4) ket thuc nhap: ";
		cin>>luaChon;
		switch(luaChon){
			case 1: tmp = new NVVP(); tmp->nhap(); ds.push_back(tmp); break;
			case 2: tmp = new NVSX(); tmp->nhap(); ds.push_back(tmp); break;
			case 3: tmp = new NVQL(); tmp->nhap(); ds.push_back(tmp); break;
			case 4: luaChon = -1; break;
			default: luaChon = 0; cout<<"Lua chon khong hop le, vui long nhap lai!\n"; break;
		}
	}while(luaChon != -1);
}
void DSNV::xuatDS(){
	for(int i = 0; i < ds.size(); i++){	
		cout<<"\t"<<i+1<<". ";ds.at(i)->xuat();
		cout<<endl;
	}
}
long long DSNV::tinhTongLuong(){
	long long kq = 0;
	for(int i = 0; i < ds.size(); i++){
		kq += ds.at(i)->tinhLuong();
	}
	return kq;
}
DSNV DSNV::timKiem(string _hoTen){
	DSNV kq;
	for(int i = 0; i < ds.size(); i++){
		if(ds.at(i)->giongTen(_hoTen)) kq.ds.push_back(ds.at(i));
	}
	
	return kq;
}
