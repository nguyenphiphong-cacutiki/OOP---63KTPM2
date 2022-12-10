#include <iostream>
using namespace std;

class SP{
	private:
		float thuc, ao;
	public:
		SP(){}
		SP(float _thuc, float _ao);
		
		friend ostream & operator <<(ostream &out,const SP x){
			if(x.ao<0){
				out<<x.thuc<<" - "<<-x.ao<<"i";
			}else{
				out<<x.thuc<<" + "<<x.ao<<"i";
			}
			return out;
		}
		friend istream & operator >>(istream &in, SP &x){
			cout<<"Nhap so phuc:\n thuc = "; in>>x.thuc;
			cout<<" ao = "; in>>x.ao;
			return in;
		}
		SP operator +(const SP &x);
		SP operator -(const SP &x);
		friend SP operator *(const SP &x, const SP &y);
		friend SP operator /(const SP &x, const SP &y);
		friend bool operator ==(const SP &x, const SP &y);
		
		
		~SP(){
		}
};

// ham main
int main(){
	SP a, b;
	cin>>a;
	cin>>b;
	
	cout<<"a la: "<<a<<"\nb la: "<<b;
//	SP phepCong = a + b;
//	SP phepTru = a - b;
//	SP phepNhan = a * b;
//	SP phepChia = a / b;
	cout<<"\nTong a va b: "<< a + b<<endl;
	cout<<"Hieu a va b: "<< a - b<<endl;
	cout<<"Nhan a va b: "<< a * b<<endl;
	cout<<"Chia va b: "<<a / b<<endl;
	
	if(a == b){
		cout<<a <<" = "<<b;
	}else{
		cout<<a<<" # "<<b;
	}
	
}

// Dinh nghia lop so phuc
SP::SP(float _thuc, float _ao){
			thuc = _thuc;
			ao = _ao;
}
SP SP:: operator +(const SP &x){
	SP kq;
	kq.thuc = this->thuc + x.thuc;
	kq.ao = this->ao + x.ao;
	return kq;
} 
SP SP:: operator -(const SP &x){
	SP kq;
	kq.thuc = this->thuc - x.thuc;
	kq.ao = this->ao - x.ao;
	return kq;
} 
bool operator ==(const SP &x, const SP &y){
	if(x.thuc == y.thuc && x.ao == y.ao) return true;
	else return false;
}  
SP operator *(const SP &x, const SP &y){
	SP kq;
	kq.thuc = x.thuc * y.thuc - x.ao * y.ao;
	kq.ao = x.thuc * y.ao + x.ao * y.thuc;
	return kq;
} 
SP operator /(const SP &x, const SP &y){
	SP kq, splhCuaMau(y.thuc, -y.ao);
	float mauSo = y.thuc * y.thuc + y.ao * y.ao;
	SP kq_tam = x * splhCuaMau;
	kq.thuc = kq_tam.thuc/mauSo;
	kq.ao = kq_tam.ao/mauSo;
	return kq;
} 

