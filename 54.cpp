#include <iostream>
#include <vector>
#include <set>
#include <queue>

int main() {
    int N;
    std::cin >> N;
    std::vector<int> degree(N+1, 0); // 진입차수
    std::vector<int> weight(N+1); // 각 노드의 건설시간
    std::vector<std::vector<int>> edges(N+1);
    for (int i = 1; i < N+1; i++) {
        int buffer = 0;
        std::cin >> buffer;
        weight[i] = buffer;
        int tmp = 0;

        while (buffer != -1) {
            std::cin >> buffer;
            if (buffer == -1) break;
            tmp ++;
            edges[buffer].push_back(i);
        }
        degree[i] = tmp;
    }

    std::queue<int> que;
    for (int i = 1; i < N+1; i++) {
        if (degree[i] == 0) {
            que.push(i);

        }
    }

    std::vector<int> result(N+1, 0);
    while(!que.empty()) {
        int target = que.front();
        que.pop();
        for (int dst: edges[target]) {
            degree[dst]--;
            result[dst] = std::max(result[dst], result[target] + weight[target]);
            que.push(dst);
        }
    }
    for (int i = 1; i < N + 1; i++) {
        std::cout << result[i] + weight[i] << std::endl;
    }


    return 0;
}