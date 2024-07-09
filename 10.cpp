#include <iostream>
#include <deque>
#include <algorithm>
#define MIN 0
int main() {
    int N;
    int L;
    std::cin >> N;
    std::cin >> L;
    std::deque<int> vec(N);
    for (int i = 0; i < N; i++) {
        std::cin >> vec[i];
    }
    std::deque<int> window(0);
    std::deque<int>::iterator iter;
    for (iter = window.begin(); iter != window.end(); iter++) {
        std::cout << *iter << " ";
    }
    for (int i = 0; i < N; i++) {
        window.push_back(vec[i]);
        if (i - L + 1 > 0) {
            window.pop_front();
        }
        std::cout << *min_element(window.begin(), window.end()) << " ";
    }
    return 0;
}



// 3 5 1 3 5 1 1 1 3 3 5 3 3 5

// 3 3 1 1 1 1 1 1 1 1 3 3 3 3


// 3

// 3 3

// 3 3 1

//   3 1 1

//     1 1 1