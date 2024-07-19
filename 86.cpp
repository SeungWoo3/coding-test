#include <iostream>
#include <vector>

int main() {
    int N;
    std::cin >> N;

    std::vector<long> num_0(N, -1);
    std::vector<long> num_1(N, -1);
    num_0[0] = 0;
    num_1[0] = 1;
    for (int i = 1; i < N; i++) {
        num_0[i] = num_0[i-1] + num_1[i-1];
        num_1[i] = num_0[i-1];
    }
    std::cout << num_0[N-1] + num_1[N-1];
    return 0;
}