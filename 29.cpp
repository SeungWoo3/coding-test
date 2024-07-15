#include <iostream>
#include <vector>
#include <algorithm>

int search(int list[], int length, int key);
int main() {
    int N, M;

    std::cin >> N;
    int Ns[N] = {0};
    for (int i = 0; i < N; i++) {
        std::cin >> Ns[i];
    }
    std::cin >> M;
    int Ms[M] = {0};
    for (int j = 0; j < M; j++) {
        std::cin >> Ms[j];
    }

    std::sort(Ns, Ns + N);

    for (int i = 0; i < M; i++) {
        int exist = 0;
        exist = search(Ns, N, Ms[i]);
        std::cout << exist << std::endl;
    }
    std::cout << std::endl;
    for (int i = 0; i < M; i++) {
        int exist = 0;
        int start = 0;
        int end = N;
        while (start <= end) {
            int center = (start + end) / 2;
            int centerValue = Ns[center];
            if (Ms[i] > centerValue) {
                start = center + 1;
            }
            else if (Ms[i] < centerValue) {
                end = center - 1;
            }
            else {
                exist = 1;
                break;
            }
        }
        std::cout << exist << std::endl;
        
    }
    return 0;
}

int search(int list[], int length, int key) {
    if (length == 1) {
        if (list[0] == key) {
            return 1;
        }
        else return 0;
    }
    else {
        int center = length / 2;
        if (search(list, center, key) == 1 || search(list+center, length-center, key) == 1) {
            return 1;
        }
        else return 0;
    }
}