#include <iostream>
#include <string.h>

#include "makeTen.h"

int main(int argc, char **argv)
{
    calc_Ten numbers[4];
    calc_Ten ans;

    if ((argc != 2) || (strlen(argv[1]) != 4)) {
        std::cout << "usage: " << argv[0] << " (4 digits number)" << std::endl;
        return 0;
    }

    for (int i = 0; i < 4; i++)
    {
        numbers[i].set_fraction_num(argv[1][i]);
    }

    ans.solve(numbers, 4);
}