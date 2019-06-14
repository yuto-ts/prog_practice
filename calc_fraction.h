#include <iostream>

class calc_fraction
{
public:
    calc_fraction& set(int, int = 1);
    calc_fraction& reduce(); // 約分
    calc_fraction& reduce(calc_fraction&); //通分
    calc_fraction& add(calc_fraction&, calc_fraction&);
    calc_fraction& sub(calc_fraction&, calc_fraction&);
    calc_fraction& mul(calc_fraction&, calc_fraction&);
    calc_fraction& div(calc_fraction&, calc_fraction&);
    void           print();
    bool           lessTen(); //10比較
    bool           zero_check();
    int            gcd(int,int);

private:
    int num;
    int den;
};

calc_fraction& calc_fraction::set(int n, int d)
{
    num = n;
    den = d;
    reduce();
    return *this;
}

calc_fraction& calc_fraction::reduce()
{
    int g = gcd(num, den);
    num /= g;
    den /= g;
}

calc_fraction& calc_fraction::reduce(calc_fraction& fb){
    int d = den;
    num *= fb.den;
    den *= fb.den;
    fb.den *= d;
    fb.num *= d;
    return *this;
}

calc_fraction& calc_fraction::add(calc_fraction& fa, calc_fraction& fb){
    fa.reduce(fb);
    num = fa.num + fb.num;
    den = fa.den;
    reduce();
    fa.reduce();
    fb.reduce();
    return *this;
}

calc_fraction& calc_fraction::sub(calc_fraction& fa, calc_fraction& fb){
    fa.reduce(fb);
    num = fa.num - fb.num;
    den = fa.den;
    reduce();
    fa.reduce();
    fb.reduce();
    return *this;
}

calc_fraction& calc_fraction::mul(calc_fraction& fa, calc_fraction& fb){
    num = fa.num * fb.num;
    den = fa.den * fb.den;
    reduce();
    return *this;
}

calc_fraction& calc_fraction::div(calc_fraction& fa, calc_fraction& fb){
    num = fa.num * fb.den;
    den = fa.den * fb.num;
    reduce();
    return *this;
}

void calc_fraction::print(){
    std::cout << num << "/" << den << std::endl;
}

bool calc_fraction::lessTen(){
    return num == 10 && den == 1;
}

bool calc_fraction::zero_check(){
    if (num == 0){
        return 0;
    }
    return 1;
}

int calc_fraction::gcd(int x, int y){
    while(y){
        int w = x % y;
            x = y;
            y = w;
    }
    return x;
}