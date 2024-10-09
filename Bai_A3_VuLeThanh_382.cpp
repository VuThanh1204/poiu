#include <iostream>
#include <cstring>
#include <iomanip>
#include <fstream>

using namespace std;

class fraction{
    private:
        float numerator, denominator;
    public:
        fraction();
        fraction(float u, float v);
        fraction operator * (fraction y);
        float operator ! ();
    friend istream& operator >> (istream& in, fraction& a);
    friend ostream& operator << (ostream& out, fraction a);
};

fraction::fraction(){
    this->numerator = 0;
    this->denominator = 1;
}

fraction::fraction(float a, float b){
    this->numerator = a;
    this->denominator = b;
}

fraction fraction::operator * (fraction y){
    fraction result;
        result.numerator = this->numerator*y.numerator;
        result.denominator = this->denominator*y.denominator;
    return result;
}

float fraction::operator ! (){
    return numerator / (denominator * 1.0);
}

istream& operator >> (istream& in, fraction& a){
    cout << "\nNhap tu so: ";          in >> a.numerator;        cin.ignore();
    cout << "Nhap mau so: ";           in >> a.denominator;      cin.ignore();
    return in;
}
ostream& operator << (ostream& out, fraction a){
    out << a.numerator << "/" << a.denominator;
    return out;
}

int main(){
    fraction a, b, c;
    ofstream FILE(("PHAN_SO.txt"), ios::out);
    cout << "NHAP CAC PHAN SO";
    cin >> a >> b;
    cout << "\nGia tri cua 2 phan so vua nhap la: " << a << " va " << b << endl;
    c = a * b;
    float d = !c;
    cout << "\nTich cua 2 phan so la: " << c << endl;
    FILE << "Tich cua 2 phan so vua nhap: " << c;       FILE.close();
    cout << "\nGia tri cua phan so vua tinh la: " << d << endl;
    return 0;
}