#include <vector>
#include <iostream>

int main(){
    // std::cout << "aaaaa" << std::endl;
    std::vector<int> data{3, 1, 4, 1, 5, 9, 2, 6, 5, 3};
    
    for (int i=0; i<data.size(); i++){
        printf("%d\n", data[i]);
        data.push_back(123);
        // if (i==(data.size())){
        //     data.push_back(123);
        //     printf("%d\n", data[10]);
        // }
    
    }
}