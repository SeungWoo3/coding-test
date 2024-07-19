#include <iostream>
#include <vector>

int main(){
    int N;
    std::cin >> N;
    std::vector<long> factorial(N+1, 1);
    for (int i = 1; i < N+1; i++) {
        factorial[i] = factorial[i-1] * i;
    }

    int task = 0;
    std::cin >> task;
    if (task == 1) {
        int k;
        std::cin >> k;
        k--;
        std::vector<int> chosen(N+1, 0);
        for (int i = 1; i < N+1; i++) {
            int idx = k / factorial[N-i];
            idx++;
            k = k % factorial[N-i];

            int cnt = 0;
            for (int num = 1; num < N+1; num++) {
                if (chosen[num] == 1){
                    cnt ++;
                }
                if (idx + cnt == num) {
                    chosen[num] = 1;
                    std::cout << num << " ";
                    break;
                }
            }
        }
    }
    else if (task == 2) {
        std::vector<int> chosen(N+1, 0);
        int cnt = 1;
        for (int i = 1; i < N+1; i++) {
            int target;
            std::cin >> target;
            int idx = 1;
            for (int j = 1; j < N+1; j++) {
                if (target == j) {
                    chosen[j] = 1;
                    break;
                }
                else if (chosen[j] == 0) {
                    idx ++;
                }
            }
            cnt += (idx-1) * factorial[N-i];
        }
        std::cout << cnt << " ";
    }



    return 0;
}