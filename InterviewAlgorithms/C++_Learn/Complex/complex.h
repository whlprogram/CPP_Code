#ifndef _MYCOMPLEX_
#define _MYCOMPLEX_
//声明
class complex;
complex& _doapl (complex* ths, const complex& r);
complex& _doami (complex* ths, const complex& r);
complex& _doaml (complex* ths, const complex& r);

class complex{
public:
    complex (double r=0, double i=0) : re ( r ), im ( i ) {}
    complex& operator += (const complex&);
    complex& operator -= (const complex&);
    complex& operator *= (const complex&);
    complex& operator /= (const complex&);
    double real() const { return re; }//求复数真值
    double imag() const { return im; }//求复数虚值
private:
    double re, im;

    friend complex& _doapl (complex *, const complex&);
    friend complex& _doami (complex *, const complex&);
    friend complex& _doaml (complex *, const complex&);
};

//定义
inline complex&
_doapl(complex* ths, const complex& r)
{
    ths->re += r.re;
    ths->im += r.im;
    return *ths;
}

inline complex&
_doami(complex* ths, const complex& r)
{
    ths->re -= r.re;
    ths->im -= r.im;
    return *ths;
}

inline complex&
_doaml(complex* ths, const complex& r)
{
    double f = ths->re * r.re - ths->im * r.im;
    ths->im = ths->re * r.im + ths->im * r.re;
    ths->re = f;
    return *ths;
}
//重载+=运算符
inline complex&
complex::operator += (const complex& r)
{
    return _doapl(this, r);
}
//重载-=运算符
inline complex&
complex::operator -= (const complex& r)
{
    return _doami(this, r);
}
//重载*=运算符
inline complex&
complex::operator *= (const complex& r)
{
    return _doaml(this, r);
}
//重载/=运算符

//重载 + 运算符
inline complex
operator + (const complex& x,const complex& y)
{
    return complex(x.real()+y.real(), x.imag()+y.imag());
}
inline complex
operator + (const complex& x, double y)
{
    return complex(x.real()+y, x.imag());
}
inline complex
operator + (double x, const complex& y)
{
    return complex(x+y.real(), y.imag());
}
//重载 - 运算符
inline complex
operator - (const complex& x,const complex& y)
{
    return complex(x.real()-y.real(), x.imag()-y.imag());
}
inline complex
operator - (const complex& x, double y)
{
    return complex(x.real()-y, x.imag());
}
inline complex
operator - (double x, const complex& y)
{
    return complex(x-y.real(), -y.imag());
}
//重载 * 运算符
inline complex
operator * (const complex& x,const complex& y)
{
    return complex(x.real()*y.real() - x.imag()*y.imag(),
                   x.real()*y.imag() + x.imag()*y.real());
}
inline complex
operator * (const complex& x, double y)
{
    return complex(x.real()*y, x.imag()*y);
}
inline complex
operator * (double x, const complex& y)
{
    return complex(x*y.real(), x*y.imag());
}
//重载 / 运算符
inline complex
operator / (const complex& x, double y)
{
    return complex(x.real()/y, x.imag()/y);
}
//重载 正负号
inline complex
operator + (const complex& x)
{
    return x;
}
inline complex
operator - (const complex& x)
{
    return complex(-x.real(), -x.imag());
}
//重载 == 运算符
inline bool
operator == (const complex& x, const complex& y)
{
    return x.real()==y.real() && x.imag()==y.imag();
}
inline bool
operator == (const complex& x, double y)
{
    return x.real()==y && x.imag()==0;
}
inline bool
operator == (double x, const complex& y)
{
    return x==y.real() && y.imag()==0;
}
//重载 != 运算符
inline bool
operator != (const complex& x, const complex& y)
{
    return x.real()!=y.real() || x.imag()!=y.imag();
}
inline bool
operator != (const complex& x, double y)
{
    return x.real()!=y || x.imag()!=0;
}
inline bool
operator != (double x, const complex& y)
{
    return x!=y.real() || y.imag()!=0;
}
#include <cmath>

inline complex
polar (double r, double t)
{
    return complex(r*cos(t), r*sin(t));
}
//共轭复数
inline complex
conj (const complex& x)
{
    return complex(x.real(), -x.imag());
}
inline double
norm (const complex& x)
{
    return x.real()*x.real() + x.imag()*x.imag();
}
#endif // _MYCOMPLEX_
