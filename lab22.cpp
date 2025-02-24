#include<iostream>
#include<cmath>
using namespace std;

class ComplexNumber{				
	public:
		double real;
		double imag;
		ComplexNumber(double,double);
		ComplexNumber operator+(const ComplexNumber &);
		ComplexNumber operator-(const ComplexNumber &);
		ComplexNumber operator*(const ComplexNumber &);
		ComplexNumber operator/(const ComplexNumber &);
		bool operator==(const ComplexNumber &);
		double abs();
		double angle();
		//Add friend non member เขียนเพื่อให้หาได้ง่ายขึ้น
		friend ostream & operator<<(ostream &, const ComplexNumber &);
		friend ComplexNumber operator+(double , const ComplexNumber &);
		friend ComplexNumber operator-(double , const ComplexNumber &);
		friend ComplexNumber operator*(double , const ComplexNumber &);
		friend ComplexNumber operator/(double , const ComplexNumber &);
};

ComplexNumber::ComplexNumber(double x = 0,double y = 0){
	real = x; imag = y;
}

ComplexNumber ComplexNumber::operator+(const ComplexNumber &c){
	return ComplexNumber(real+c.real,imag+c.imag);
}

ComplexNumber ComplexNumber::operator-(const ComplexNumber &c){
	return ComplexNumber(real-c.real,imag-c.imag);
}

//Write your code here
//Use for cout class
ostream & operator<<(ostream &os, const ComplexNumber &c) {
    if (c.real == 0 && c.imag == 0) {
        os << "0";
    } else if (c.real == 0) {
        os << c.imag << "i";
    } else if (c.imag == 0) {
        os << c.real;
    } else {
        os << c.real;
        if (c.imag < 0) {
            os << c.imag << "i";
        } else {
            os << "+" << c.imag << "i";
        }
    }
    return os;
}
//Double + ComplexNumber
ComplexNumber operator+(double s, const ComplexNumber &c){
	return ComplexNumber(s+c.real, c.imag);
}
//Double - ComplexNumber
ComplexNumber operator-(double s, const ComplexNumber &c){
	return ComplexNumber(s-c.real, -c.imag);
}
// * ComplexNumber-> Double
ComplexNumber ComplexNumber::operator*(const ComplexNumber &c){
	return ComplexNumber(real*c.real - imag*c.imag, real*c.imag + imag*c.real);
}
// * Double -> ComplexNumber
ComplexNumber operator*(double s, const ComplexNumber &c){
    return ComplexNumber(s * c.real, s * c.imag);
}
// / ComplexNumber-> Double
ComplexNumber ComplexNumber::operator/(const ComplexNumber &c){
	double NumberFortest = c.real*c.real + c.imag*c.imag;
    return ComplexNumber((real*c.real + imag*c.imag)/NumberFortest, (imag*c.real - real*c.imag)/NumberFortest);
}
// / Double -> ComplexNumber
ComplexNumber operator/(double s, const ComplexNumber &c){
	double NumberFortest = c.real*c.real + c.imag*c.imag;
    return ComplexNumber((s*c.real)/NumberFortest, (-s*c.imag)/NumberFortest);
}
// == ComplexNumber -> Double
bool ComplexNumber::operator==(const ComplexNumber &c){
	if(real==c.real && imag==c.imag) return true;
	else return false;
}
// == Double -> ComplexNumber
bool operator==(double d,const ComplexNumber &c){
	if(d==c.real && d==c.imag) return true;
	else return false;
}
//double abs();
double ComplexNumber::abs(){
    return sqrt(real*real + imag*imag);
}
//double angle();
double ComplexNumber::angle() {
    return atan2(imag, real) * 180 / M_PI;
}
//

int main(){
	ComplexNumber a(1.5,2),b(3.2,-2.5),c(-1,1.2);	
	cout << a << "\n";
	cout << b << "\n";
	cout << c << "\n";
	cout << a+2.5 << "\n";
	cout << 2.5+a << "\n";
	cout << a-1.5 << "\n";
	cout << 1.5-a << "\n";
	cout << b+ComplexNumber(0,2.5) << "\n";
	cout << c-c << "\n";
	cout << "-----------------------------------\n";
	
	ComplexNumber d = (a+b)/c;
	ComplexNumber e = b/(a-c);
	cout << d << "\n";
	cout << e << "\n";
	cout << c*2 << "\n";
	cout << 0.5*c << "\n";
	cout << 1/c << "\n";
	cout << "-----------------------------------\n";
	
	cout << ComplexNumber(1,1).abs() << "\n";
	cout << ComplexNumber(-1,1).abs() << "\n";
	cout << ComplexNumber(1.5,2.4).abs() << "\n";
	cout << ComplexNumber(3,4).abs() << "\n";
	cout << ComplexNumber(69,-9).abs() << "\n";		
	cout << "-----------------------------------\n";	
	
	cout << ComplexNumber(1,1).angle() << "\n";
	cout << ComplexNumber(-1,1).angle() << "\n";
	cout << ComplexNumber(-1,-1).angle() << "\n";
	cout << ComplexNumber(1,-1).angle() << "\n";
	cout << ComplexNumber(5,2).angle() << "\n";
	cout << "-----------------------------------\n";
	
	cout << (ComplexNumber(1,1) == ComplexNumber(1,2)) << "\n";
	cout << (ComplexNumber(1,1) == 1) << "\n";
	cout << (0 == ComplexNumber()) << "\n";
}
