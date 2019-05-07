#include <iostream>  // for cout
#include <stdio.h>   // for printf()

#define L  158             // 計算桁数
#define L2 ((L + 7) / 8)  // 配列サイズ
#define N  100             // 計算個数

using namespace std;

/*
 * 計算クラス
 */
class Calc
{
    // 各種変数
    int k, i;   // LOOP インデックス
    int carry;  // 繰り上がり
    long w;     // 被乗数ワーク

    public:
        // 計算
        void calc();
        // ロング * ショート
        void lmul(int *, int, int *);
        // 結果出力
        void display(int *);
};

/*
 * 計算
 */
void Calc::calc()
{
    // 配列宣言
    int s[L2];

    // 配列初期化
    for (k = 0; k < L2 - 1; k++)
        s[k] = 0;
        s[L2 - 1] = 1;

    for (k = 1; k <= N; k++) {
        // 計算
        lmul(s, k, s);

        // 結果出力
        printf("%2d!=", k);
        display(s);
    }
}

/*
 * ロング * ショート
 */
void Calc::lmul(int a[], int b, int c[])
{
    carry = 0;
    for (i = L2 - 1; i >=0; i--) {
        w = a[i];
        c[i] = (w * b + carry) % 100000000;
        carry = (w * b + carry) / 100000000;
    }
}

/*
 * 結果出力
 */
void Calc::display(int s[])
{
    for (i = 0; i < L2; i++)
        printf("%08d", s[i]);
    printf("\n");
}

/*
 * メイン処理
 */
int main()
{
    try
    {
        // 計算クラスインスタンス化
        Calc objCalc;

        // 階乗計算
        objCalc.calc();
    }
    catch (...) {
        cout << "例外発生！" << endl;
        return -1;
    }

    // 正常終了
    return 0;
}



// #include <stdio.h>
// #define N 60
// #define FACT 30

// main(){

//     int a[N];
//     int i, n, carry;

//     for(int i=1; i<=N; i++)
//     printf()
// }