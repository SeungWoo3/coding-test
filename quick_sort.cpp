#include <iostream>
void quick_sort(int *array, int start, int end) {
    if (start >= end) return;
    int pivot = end;
    int i = start;
    int j = end - 1;
    while(i <= j) {
        while (array[i] <= array[pivot] && i < end) {
            i += 1;
        }
        while (array[j] > array[pivot] && j >= start) {
            j -= 1;
        }
        if (i < j) {
            int tmp = array[i];
            array[i] = array[j];
            array[j] = tmp;
        }
    }
    int tmp = array[i];
    array[i] = array[pivot];
    array[pivot] = tmp;
    quick_sort(array, start, j);
    quick_sort(array, i+1, end);
}
int main() {
    int N;
    int array[N];
    std::cin >> N;
    for (int i = 0; i < N; i++) {
        std::cin >> array[i];
    }
    quick_sort(array, 0, N-1);
    for (int i = 0; i < N; i++) {
        std::cout << array[i];
    }
}
