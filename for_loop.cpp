#include <iostream>
#include <vector>

int main() {
    int array[] = {1,2,3,4,5};
    std::vector<int> vec = {-1,-2,-3};
    for (int i: array) {
        std::cout << i <<" ";
    }
    std::cout << std::endl;
    for (int j: vec) {
        std::cout << j << " ";
    }
}