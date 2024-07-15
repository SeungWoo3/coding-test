#include <iostream>
#include <cmath>
#include <vector>

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    int N, M;
    std::cin >> N >> M;
    std::vector<int> array(M+1, 1);

    array[0] = false;
    array[1] = false;

    int idx = 2;
    while (idx <= std::sqrt(M)) {
        for(int i = 2; i*idx <= M; i++) {
            array[i*idx] = false;
        }
        while (true) {
            idx++;
            if (array[idx] == true || idx > std::sqrt(M)) {
                break;
            }
        }
        
    }
    for (int i = N; i < M+1; i++) {
        if (array[i] == 1) {
            std::cout << i << std::endl;
        }
    }

    return 0;
}