#include <iostream>
#include <stdlib.h>


#include <string.h>
#include <math.h>
#include <vector>

int gcd(int,int);

int gcd(int x, int y){
    while(y){
        int w = x % y;
            x = y;
            y = w;
    }
    return x;
}

class culc_fraction
{
public:
    culc_fraction& set(int, int = 1);
    culc_fraction& reduce(); // 約分
    culc_fraction& reduce(culc_fraction&); //通分
    culc_fraction& add(culc_fraction&);
    culc_fraction& sub(culc_fraction&);
    culc_fraction& mul(culc_fraction&);
    culc_fraction& div(culc_fraction&);

private:
    int num;
    int den;
};

culc_fraction& culc_fraction::set(int n, int d)
{
    num = n;
    den = d;
    reduce();
    return *this;
}

culc_fraction& culc_fraction::reduce()
{
    int g = ::gcd(num, den);
    num /= g;
    den /= g;
}

culc_fraction& culc_fraction::reduce(culc_fraction& fb){
    int d = den;
    num *= fb.den;
    den *= fb.den;
    fb.den *= d;
    fb.num *= d;
    return *this;
}

culc_fraction& culc_fraction::add(culc_fraction& fb){
    reduce(fb);
    num += fb.num;
    reduce();
    fb.reduce();
    return *this;
}

culc_fraction& culc_fraction::sub(culc_fraction& fb){
    reduce(fb);
    num -= fb.num;
    reduce();
    fb.reduce();
    return *this;
}

culc_fraction& culc_fraction::mul(culc_fraction& fb){
    num *= fb.num;
    den *= fb.den;
    reduce();
    return *this;
}

culc_fraction& culc_fraction::div(culc_fraction& fb){
    num *= fb.den;
    den *= fb.num;
    reduce();
    return *this;
}



class culc_Ten //: public culc_fraction
{
public:
    culc_Ten& set_num(char);
    auto      set_nums(culc_Ten *numbers, char argv);
    culc_Ten& solve();
private:
    int num;
    std::vector<int> str{1};
};

culc_Ten& culc_Ten::set_num(char argv){
    num = (int)(argv  - '0');
    str[0] = argv;
    str[1] = 0;
    std::cout << num;

    return *this;
}



auto culc_Ten::set_nums(culc_Ten *numbers, char argv){
    for (int i = 0; i < 4; i++){
        numbers[i].set_num(argv);
    }
}

int main(int argc, char **argv)
{
    culc_Ten numbers[4];

    if ((argc != 2) || (strlen(argv[1]) != 4)) {
        printf("usage: %s (4 digits number)\n", argv[0]);
        return 0;
    }

    for (int i = 0; i < 4; i++)
    {
        numbers[i].set_num(argv[1][i]);
    }


    
    // solve(numbers, 4);
}