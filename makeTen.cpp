#include <iostream>
#include <stdlib.h>


#include <string.h>
#include <math.h>
#include <vector>

class fraction
{

};

class culc : public fraction
{
public:
    culc& set();
    culc& add(culc&, );
    culc& sub();
    culc& mul();
    culc& div();
    culc& solve();
private:
    double num;
    std::vector<int> buf{1};
};

void main(int argc, char **argv)
{
    struct numstr numbers[4];
    int i;

    if ((argc != 2) || (strlen(argv[1]) != 4)) {
        printf("usage: %s (4 digits number)\n", argv[0]);
        exit(1);
    }

    for (i=0; i<4; i++) {
        numbers[i].num = (double)(argv[1][i] - '0');
        numbers[i].str[0] = argv[1][i];
        numbers[i].str[1] = 0;
    }

    solve(numbers, 4);
}