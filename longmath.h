#include <vector>

class Longint {
public:
    void multiply(int n);
    void display() const;
private:
    // void overflow(int n);
    std::vector<int> buf{1};
    int carry = 0;
};

void Longint::multiply(int n) {
    carry = 0;
    for (int i=0; i!=buf.size(); ++i) {
        buf[i] = buf[i]*n;
        buf[i] = buf[i]+carry;
        carry = buf[i]/10;
        buf[i] = buf[i]%10;
        if (i==(buf.size()-1) && carry>=0) {
            int carrybuf=carry;
            unsigned digit=0;
            while(carrybuf!=0){
                carrybuf/=10;
                digit++;
            }
            for (int i=digit; i>=1; i--){
                buf.push_back(carry%10);
                carry = carry/10;
            }
            break;
        }
    }
}

void Longint::display() const {
    for (int i=(buf.size()-1); i>=0; i--) {
        printf("%d", buf[i]);
    } 
    printf("\n");
}