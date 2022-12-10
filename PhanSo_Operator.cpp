#include <iostream>
using namespace std;

int ucln(int a, int b)
{
    return ((b == 0) ? a : ucln(b, a % b));
}

/*=============== Khai bao lop PhanSo ===============*/
class PhanSo
{
private:
    int ts, ms;
    void toiGian();

public:
    PhanSo();                // Ham tao mac dinh khong tham so
    PhanSo(int tu, int mau); // Ham tao mac dinh day du tham so
 
     // Dinh nghia cong tru nhan chia
    PhanSo operator+(const PhanSo &ps);
    PhanSo operator-(const PhanSo &ps);
    friend PhanSo operator*(const PhanSo &ps1, const PhanSo &ps2);
    friend PhanSo operator/(const PhanSo &ps1, const PhanSo &ps2);

    // Nap chong toan tu nhap xuat
    friend istream &operator>>(istream &in, PhanSo &ps)
    {
        cout << "Tu: ";  in >> ps.ts;
        cout << "Mau: "; in >> ps.ms;
        if (ps.ms == 0)
        {
            cout << "Mau so phai khac 0" << endl;
            exit(0);
        }
        ps.toiGian();
    }

    friend ostream &operator<<(ostream &out, const PhanSo &ps)
    {
        if (ps.ms == 1)
            out << ps.ts;
        else
        {
            if (ps.ts == 0)
                out << "0";
            else
                out << ps.ts << "/" << ps.ms;
        }
    }
};

/*=============== Main ===============*/
int main()
{
    PhanSo a, b;
    cout << "Nhap phan so a\n"; cin >> a;
    cout << "Nhap phan so b\n"; cin >> b;

    cout << a << " + " << b << " = " << a + b << endl;
    cout << a << " - " << b << " = " << a - b << endl;
    cout << a << " * " << b << " = " << a * b << endl;
    cout << a << " / " << b << " = " << a / b << endl;
    return 0;
}

/*=============== Dinh nghia lop PhanSo ===============*/
void PhanSo::toiGian()
{
    int uc = ucln(ts, ms);
    ts /= uc;
    ms /= uc;
    if (ms < 0)
    {
        ts = -ts;
        ms = -ms;
    }
}

PhanSo::PhanSo()
{
    ts = 0;
    ms = 1;
}

PhanSo::PhanSo(int tu, int mau)
{
    ts = tu;
    ms = mau;
    toiGian();
}

PhanSo PhanSo::operator+(const PhanSo &ps)
{
    PhanSo kq;
    kq.ts = this->ts * ps.ms + this->ms * ps.ts;
    kq.ms = this->ms * ps.ms;
    kq.toiGian();
    return kq;
}

PhanSo PhanSo::operator-(const PhanSo &ps)
{
    PhanSo kq;
    kq.ts = this->ts * ps.ms - this->ms * ps.ts;
    kq.ms = this->ms * ps.ms;
    kq.toiGian();
    return kq;
}

PhanSo operator*(const PhanSo &ps1, const PhanSo &ps2)
{
    PhanSo kq;
    kq.ts = ps1.ts * ps2.ts;
    kq.ms = ps1.ms * ps2.ms;
    kq.toiGian();
    return kq;
}

PhanSo operator/(const PhanSo &ps1, const PhanSo &ps2)
{
    PhanSo kq;
    if (ps2.ts == 0)
    {
        cout << "Loi chia 0" << endl;
        kq.ts = -1;
    }
    else
    {
        kq.ts = ps1.ts * ps2.ms;
        kq.ms = ps1.ms * ps2.ts;
        kq.toiGian();
    }
    return kq;
}
