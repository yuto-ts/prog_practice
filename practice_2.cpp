#include <stdio.h>
#include "longmath.h" 
#include <stdlib.h>

// const int fact = 200; // fact階乗を計算する

int main(int argc, char* argv[]){
    Longint longbuf;
    const int fact = atoi(argv[1]);

    for (int i=1; i<=fact; ++i){
        longbuf.multiply(i);
        if (i==fact) {
            printf("%2d! = ", i);
            longbuf.display();
        }
    } 
}