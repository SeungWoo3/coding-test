#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
    int N;
    cin >> N;

    // int array[N] = {0};
    // for (int i = 0; i < N; i++){
    //     cin >> array[i];
    // }

    // vector 로 구현 - sort 해야하기 때문 //
    
    vector<int> array(N, 0);
    for (int i = 0; i < N; i++){
        cin >> array[i];
    }
    sort(array.begin(), array.end());

    int cnt = 0;

    for (int i = 2; i < N; i++){
        int target = array[i];
        int start = 0;
        int end = i-1;
        while(start != end){
            if (array[start] + array[end] == target){
                cnt += 1;
                break;
            }
            else if (array[start] + array[end] < target){
                start += 1;
            }
            else{
                end -= 1;
        }
        }
    }
    cout << cnt;
    return 0;
}