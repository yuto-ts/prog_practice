#include <iostream>
#include <stdlib.h>


#include <string.h>
#include <math.h>
#include <vector>

// class culc_fraction
// {
// public:
//     culc_fraction& set(int, int = 1);
//     culc_fraction& reduce(); // 約分
//     culc_fraction& reduce(culc_fraction&); //通分
//     culc_fraction& add(culc_fraction&);
//     culc_fraction& sub(culc_fraction&);
//     culc_fraction& mul(culc_fraction&);
//     culc_fraction& div(culc_fraction&);

// private:
//     int num;
//     int den;
// };

class culc_Ten //: public culc_fraction
{
public:
    culc_Ten& set_num(char);
    auto culc_Ten::set_nums(culc_Ten *numbers, char argv);
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
        // exit(1);
        return 0;
    }

    for (int i = 0; i < 4; i++)
    {
        numbers[i].set_num(argv[1][i]);
    }
    
    // solve(numbers, 4);
}