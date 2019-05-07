#include <stdio.h>
#define N 158
#define FACT 100

using namespace std;

class Calc{
    int buf[N];
    int carry;
    public:
        Calc(){
            carry = 0;
            buf[0] = 1;
            for (int i=1; i<N; i++){
                buf[i] = 0;
            }

        }
        void multiply(int n);
        void display();
};

void Calc::multiply(int n){
    carry = 0;
    for (int k = 0; k<N; k++){
        buf[k] = buf[k]*n;
        buf[k] = buf[k] + carry;
        carry = buf[k]/10;
        buf[k] = buf[k]%10;
    }

}

void Calc::display(){
    for(int j=N-1; j>=0; j--){
        printf("%d",buf[j]);
    }
}

int main(){
    Calc a1;
    Calc a2;

    for (int i = 2; i<=FACT; i++){
        a1.multiply(i);
        if (i == FACT){
            printf("%2d! = ", i);
            a1.display();
            printf("\n");
        }
    }
}
// #include <stdio.h>
// #define N 158
// #define FACT 100

// main(){
//     int buf[N];
//     int carry;
//     buf[0] = 1;

    // for (int i=1; i<N; i++){
    //     buf[i] = 0;
    // }

//     for (int n=2; n<=FACT; n++){
//         carry = 0;
        
//         for (int k=0; k<N; k++){
//             buf[k] = buf[k]*n;
//             buf[k] = buf[k] + carry;
//             carry = buf[k]/10;
//             buf[k] = buf[k]%10;
//         }

//         if (n == FACT){
//             printf("%2d! = ", n);
//             for(int j=N-1; j>=0; j--){
//                 printf("%d",buf[j]);
//                 }
//         }
//     }
//     printf("\n");
// }