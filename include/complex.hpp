#ifndef __COMPLEXHPP__
#define __COMPLEXHPP__


class Complex
{
public:
	Complex(): a(0), b(0) {}
	Complex(double x, double y): a(x), b(y) {}

	Complex add(const Complex &c) const { return Complex(a + c.a, b + c.b); }
	Complex subtract(const Complex &c ) const { return Complex(a - c.a, b - c.b); }
	Complex multiply(const Complex &c ) const { return Complex(a * c.a - b * c.b, b * c.a + a * c.b); }
	Complex divide(const Complex &c ) const { return Complex((a * c.a + b * c.b) / (c.a * c.a + c.b * c.b), (b * c.a + a * c.b) / (c.a * c.a + c.b * c.b)); }

	double mag2() { return a*a + b*b; }
	double re() { return a; }
	double im() { return b; }
private:
	double a, b; //Re(z) = a Im(z) = b

};

#endif