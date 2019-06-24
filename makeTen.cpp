#include <iostream>
#include <string.h>
#include "makeTen.h"

int main(int argc, char **argv) {
    const int num_of_data = strlen(argv[1]);
    calc_Ten numbers[num_of_data];
    calc_Ten ans;

    for(int i = 0; i < num_of_data; i++) {
        numbers[i].set_fraction_num(argv[1][i]);
    }

    ans.solve(numbers, num_of_data);
}
// 名前はCalcTenが正しい，正しいインターフェースを作る，メイン関数から設計をしていく
// べき論と事情の瀬戸際なので，vectorで書けるよね，あとで変わらなそうな型で引数を受け取る．
// 
// argv -> vector
// CalcTen ct(vec);
// ct.solve();
// ct.print();
// lisp S式
// 
