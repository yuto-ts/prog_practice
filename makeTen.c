#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

struct numstr {
    double num;
    char str[14]; /* ex. "(((1+2)+3)+4)" */
};

void solve(struct numstr *numbers, int n)
{
    int i, j, k, l;
    struct numstr *new_numbers;

    if (n == 1) {
        if (fabs(numbers[0].num - 10.) < 1e-5) {
            printf("%s=10\n", numbers[0].str);
        }
        return;
    }

    new_numbers = (struct numstr *)malloc(sizeof(struct numstr) * (n-1));

    /* numbers[i]とnumbers[j]を演算 */
    for (i=0; i<n-1; i++) {
        for (j=i+1; j<n; j++) {
            /* 演算しないものをnew_numbersにコピー */
            l = 0;
            for (k=0; k<n; k++) {
                if ((k!=i)&&(k!=j)) {
                    new_numbers[l++] = numbers[k];
                }
            }
            /* 以下、演算結果をnew_numbers[l]に入れる */

            new_numbers[l].num = numbers[i].num + numbers[j].num;
            sprintf(new_numbers[l].str, "(%s+%s)", numbers[i].str, numbers[j].str);
            solve(new_numbers, n-1);

            new_numbers[l].num = numbers[i].num - numbers[j].num;
            sprintf(new_numbers[l].str, "(%s-%s)", numbers[i].str, numbers[j].str);
            solve(new_numbers, n-1);

            new_numbers[l].num = numbers[j].num - numbers[i].num;
            sprintf(new_numbers[l].str, "(%s-%s)", numbers[j].str, numbers[i].str);
            solve(new_numbers, n-1);

            new_numbers[l].num = numbers[i].num * numbers[j].num;
            sprintf(new_numbers[l].str, "(%s*%s)", numbers[i].str, numbers[j].str);
            solve(new_numbers, n-1);

            if (fabs(numbers[j].num) > 1e-5) {
                new_numbers[l].num = numbers[i].num / numbers[j].num;
                sprintf(new_numbers[l].str, "(%s/%s)", numbers[i].str, numbers[j].str);
                solve(new_numbers, n-1);
            }

            if (fabs(numbers[i].num) > 1e-5) {
                new_numbers[l].num = numbers[j].num / numbers[i].num;
                sprintf(new_numbers[l].str, "(%s/%s)", numbers[j].str, numbers[i].str);
                solve(new_numbers, n-1);
            }
        }
    }

    free(new_numbers);
}

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