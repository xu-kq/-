// guard declaration
#pragma once 

// forward declaration
#include<iostream>
class Complex;
Complex& __doapl(Complex*, const Complex&);
Complex& __doami(Complex*, const Complex&);
Complex& __doaml(Complex*, const Complex&);

class Complex{
public:
    Complex(double r = 0.0, double i = 0.0)
        : re(r), im(i)                      // initialization list
    {   }
    // operator overload
    // composite assignment operator
    Complex& operator += (const Complex&);
    Complex& operator -= (const Complex&);
    Complex& operator *= (const Complex&);

    // const member function
    double real() const {   return re;  }
    double imag() const {   return im;  }
private:
    double re, im;
    // friend
    friend Complex& __doapl(Complex* ths, const Complex& rhs);
    friend Complex& __doami(Complex* ths, const Complex& rhs);
    friend Complex& __doaml(Complex* ths, const Complex& rhs);
};

inline
Complex& __doapl(Complex* ths, const Complex& rhs)
{
    ths->re += rhs.re;
    ths->im += rhs.im;
    return *ths;
}
inline
Complex& Complex::operator += (const Complex& rhs)
{
    return __doapl(this, rhs);
}

inline
Complex& __doami(Complex* ths, const Complex& rhs)
{
    ths->re -= rhs.re;
    ths->im -= rhs.im;
    return *ths;
}
inline
Complex& Complex::operator -= (const Complex& rhs)
{
    return __doami(this, rhs);
}

inline
Complex& __doaml(Complex* ths, const Complex& rhs)
{
    double re = ths->re * rhs.re - ths->im * rhs.im;
    double im = ths->re * rhs.im + ths->im * rhs.re;
    ths->re = re;
    ths->im = im;
    return *ths;
}
inline
Complex& Complex::operator *= (const Complex& rhs)
{
    return __doaml(this, rhs);
}

inline
double real(const Complex& c)
{
    return c.real();
}
inline
double imag(const Complex& c)
{
    return c.imag();
}

inline
Complex operator + (const Complex& lhs, const Complex& rhs)
{
    return Complex(real(lhs)+real(rhs), imag(lhs)+imag(rhs));
}

inline
Complex operator - (const Complex& lhs, const Complex& rhs)
{
    return Complex(real(lhs)+real(rhs), imag(lhs)+imag(rhs));
}

inline
Complex operator * (const Complex& lhs, const Complex& rhs)
{
    return Complex(real(lhs)*real(rhs) - imag(lhs)+imag(rhs), real(lhs)*imag(rhs) + imag(lhs)*real(rhs));
}

inline
Complex operator + (const Complex& operand)
{
    return operand;
}

inline
Complex operator - (const Complex& operand)
{
    return Complex(-real(operand), -imag(operand));
}

inline
Complex conj(const Complex& operand)
{
    return Complex(real(operand), imag(operand));
}

inline
bool operator == (const Complex& lhs, const Complex& rhs)
{
    return real(lhs) == real(rhs) && imag(lhs) == imag(rhs);
}

inline
bool operator != (const Complex& lhs, const Complex& rhs)
{
    return real(lhs) != real(rhs) || imag(lhs) != imag(rhs);
}

inline
std::ostream& operator << (std::ostream& os, const Complex& c)
{
    os << '(' << real(c) << ", " << imag(c) << ')';
    return os;
}