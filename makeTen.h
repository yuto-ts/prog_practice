
#include <iostream>
#include <string>
#include "calc_fraction.h"

class calc_Ten : public calc_fraction
{
public:
    calc_Ten& set_num(char);
    calc_Ten& set_fraction_num(char);
    void      solve(calc_Ten* numbers, int n);

private:
    int numb;
    std::string str;
};

calc_Ten& calc_Ten::set_num(char argv){
    numb = (int)(argv  - '0');
    str = argv;
    return *this;
}


calc_Ten& calc_Ten::set_fraction_num(char argv){
    set_num(argv);
    calc_fraction::set(numb);
    return *this;
}

void calc_Ten::solve(calc_Ten* numbers, int n)
{
    calc_Ten* ans = new calc_Ten[10];

    if (n == 1) {
        if(numbers[0].lessTen()){
            std::cout << numbers[0].str << " == 10" << std::endl;
        }
        return;
    }

    for (int i=0; i<n-1; i++) {
        for (int j=i+1; j<n; j++) {
            // 計算しないものをansにコピー
            int l = 0;
            for (int k=0; k<n; k++) {
                if ((k!=i)&&(k!=j)) {
                    ans[l++] = numbers[k];
                }
            }

            // 計算結果をans[l]に入れる 
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

            if (numbers[j].zero_check()){
                ans[l].div(numbers[i], numbers[j]);
                ans[l].str = "(" + numbers[i].str + " / " + numbers[j].str + ")";
                solve(ans, n-1);
            }

            if (numbers[i].zero_check()){
                ans[l].div(numbers[j], numbers[i]);
                ans[l].str = "(" + numbers[j].str + " / " + numbers[i].str + ")";
                solve(ans, n-1);
            }
        }
    }
    delete [] ans;
}

