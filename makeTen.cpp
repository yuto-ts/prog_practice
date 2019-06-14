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
    culc_fraction& add(culc_fraction&, culc_fraction&);
    culc_fraction& sub(culc_fraction&, culc_fraction&);
    culc_fraction& mul(culc_fraction&, culc_fraction&);
    culc_fraction& div(culc_fraction&, culc_fraction&);
    void           print();
    bool           lessTen();


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

culc_fraction& culc_fraction::add(culc_fraction& fa, culc_fraction& fb){
    fa.reduce(fb);
    num = fa.num + fb.num;
    den = fa.den;
    reduce();
    fa.reduce();
    fb.reduce();
    return *this;
}

culc_fraction& culc_fraction::sub(culc_fraction& fa, culc_fraction& fb){
    fa.reduce(fb);
    num = fa.num - fb.num;
    den = fa.den;
    reduce();
    fa.reduce();
    fb.reduce();
    return *this;
}

culc_fraction& culc_fraction::mul(culc_fraction& fa, culc_fraction& fb){
    num = fa.num * fb.num;
    den = fa.den * fb.den;
    reduce();
    return *this;
}

culc_fraction& culc_fraction::div(culc_fraction& fa, culc_fraction& fb){
    num = fa.num * fb.den;
    den = fa.den * fb.num;
    reduce();
    return *this;
}


void culc_fraction::print(){
    std::cout << num << "/" << den << std::endl;
}

bool culc_fraction::lessTen(){
    if (num == 10 || den == 1){
        std::cout << num  << "/" << den << std::endl;
        return 1;
    }else{
        return 0;
    }
}

class culc_Ten : public culc_fraction
{
public:
    culc_Ten& set_num(char);
    auto      set_nums(culc_Ten *numbers, char argv);
    culc_Ten& set_fraction_num(char);
    // void      print();
    void      solve(culc_Ten* numbers, int n);
    void      set_str(culc_Ten&, culc_Ten&);
private:
    int numb;
    std::string str;
};

culc_Ten& culc_Ten::set_num(char argv){
    numb = (int)(argv  - '0');
    str = argv;
    // str[1] = 0;
    return *this;
}

auto culc_Ten::set_nums(culc_Ten *numbers, char argv){
    for (int i = 0; i < 4; i++){
        numbers[i].set_num(argv);
    }
}

culc_Ten& culc_Ten::set_fraction_num(char argv){
    set_num(argv);
    culc_fraction::set(numb);
    return *this;
}



void culc_Ten::solve(culc_Ten* numbers, int n)
{
    culc_Ten* ans = new culc_Ten[10];

    if (n == 1) {
        if(numbers[0].lessTen()){
            std::cout << numbers[0].str << " == 10" << std::endl;
        }
        return;
    }

    /* numbers[i]とnumbers[j]を演算 */
    for (int i=0; i<n-1; i++) {
        for (int j=i+1; j<n; j++) {
            /* 演算しないものをnew_numbersにコピー */
            int l = 0;
            for (int k=0; k<n; k++) {
                if ((k!=i)&&(k!=j)) {
                    ans[l++] = numbers[k];
                }
            }
            /* 以下、演算結果をnew_numbers[l]に入れる */

            ans[l].add(numbers[i], numbers[j]);
            ans[l].str = "(" + numbers[i].str + " + " + numbers[j].str + ")";
            solve(ans, n-1);

            ans[l].sub(numbers[i], numbers[j]);
            ans[l].str = "(" + numbers[i].str + " - " + numbers[j].str + ")";
            solve(ans, n-1);

            ans[l].sub(numbers[j], numbers[i]);
            ans[l].str = "(" + numbers[j].str + " - " + numbers[i].str + ")";
            solve(ans, n-1);

            ans[l].mul(numbers[i], numbers[j]);
            ans[l].str = "(" + numbers[i].str + " * " + numbers[j].str + ")";
            solve(ans, n-1);

            ans[l].div(numbers[i], numbers[j]);
            ans[l].str = "(" + numbers[i].str + " / " + numbers[j].str + ")";
            solve(ans, n-1);

            ans[l].div(numbers[j], numbers[i]);
            ans[l].str = "(" + numbers[j].str + " / " + numbers[i].str + ")";
            solve(ans, n-1);
        }
    }

    delete [] ans;
}


int main(int argc, char **argv)
{
    // culc_Ten* numbers = new culc_Ten[4];
    culc_Ten numbers[4];
    culc_Ten ans;

    if ((argc != 2) || (strlen(argv[1]) != 4)) {
        printf("usage: %s (4 digits number)\n", argv[0]);
        return 0;
    }

    for (int i = 0; i < 4; i++)
    {
        numbers[i].set_fraction_num(argv[1][i]);
    }

    ans.add(numbers[0],  numbers[1]);
    ans.print();
    ans.solve(numbers, 4);
}