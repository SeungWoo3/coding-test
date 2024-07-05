#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    std::vector<int> V = {1, 2, 3, 4};
    std::vector<int>::iterator iter;
    for (iter = V.begin(); iter != V.end(); iter++)
        std::cout << *iter << "!" << std::endl;
        
    // iter는 vector의 포인터
    // begin(), end()는 시작과 끝의 포인터를 반환


    return 0;
}