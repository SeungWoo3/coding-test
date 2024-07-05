#include <iostream>
using namespace std;

int main(){
    int N, M;
    cin >> N >> M;
    
    int input[N + 1] {0};
    for (int i = 1; i < N+1; i++){
        cin >> input[i];
    }

    int sum_array[N + 1] = {0};
    int sum_tmp = 0;
    for (int i = 0; i < N + 1; i++){
        sum_tmp += input[i];
        sum_array[i] = sum_tmp;
    }

    for (int i = 0; i < M; i++){
        int start, end;
        cin >> start >> end;
        
        int sum;
        sum = sum_array[end] - sum_array[start-1];
        cout << sum << endl;
    }

    return 0;
}