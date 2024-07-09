#include <iostream>
#include <vector>
void quick_sort(std::vector<int>::iterator start, std::vector<int>::iterator end) {
    if (start == end) return;
    std::vector<int>::iterator pivot = end;
    std::vector<int>::iterator i = start;
    std::vector<int>::iterator j = end - 1;
    while(i != j) {
        if (*i <= *pivot) {
            i += 1;
        }
        if (*j > *pivot) {
            j -= 1;
        }
        if (*i > *pivot && *j <= *pivot){
            int tmp = *i;
            *i = *j;
            *j = tmp;
        }
    }
    int tmp = *j;
    *j = *pivot;
    *pivot = tmp;
    quick_sort(start, j-1);
    quick_sort(j+1, end);
    return;
}
int main() {
    int N;
    std::cin >> N;
    std::vector<int> vec(N);
    for (int i = 0; i < N; i++) {
        std::cin >> vec[i];
        std::cout << "vec[]";
    }
    std::cout << "dd";
    std::vector<int>::iterator iter;
    quick_sort(vec.begin(), vec.end() - 1);
    for (iter = vec.begin(); iter != vec.end(); iter++) {
        std::cout << *iter << std::endl;
    }
}