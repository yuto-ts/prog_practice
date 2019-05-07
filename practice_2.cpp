#include <stdio.h>
#include "longmath.h" 

const int fact = 200; // fact階乗を計算する

int main(){
    Longint longbuf;

    for (int i=1; i<=fact; ++i){
        longbuf.multiply(i);
        if (i==fact) {
            printf("%2d! = ", i);
            longbuf.display();
        }
    } 
}