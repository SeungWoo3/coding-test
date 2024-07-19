#include <iostream>
#include <vector>

int main() {
    int N, M;
    long long K;
    std::cin >> N >> M >> K;
    std::vector<std::vector<long long>> comb(N+M+1, std::vector<long long>(N+M+1, 0));
    for (int i = 0; i <= N+M; i++) {
        for (int j = 0; j <= i; j++) {
            if (j == 0 || j == i) {
                comb[i][j] = 1;
            }
            else{
                comb[i][j] = comb[i-1][j-1] + comb[i-1][j];
            }
            std::cout << comb[i][j] << " ";
        }
        std::cout << std::endl;
    }
    if (K > comb[N+M][N] || K <= 0) {
       std::cout << -1; 
    }
    else {
        int length = N + M;
        for (int idx = 1; idx <= length; idx++) {
            if (K <= comb[N+M-1][M]) {
                std::cout << 'a';
                N--;
            }
            else {
                std::cout << 'z';
                K -= comb[N+M-1][M];
                M--;
            }
        }

    }
}
