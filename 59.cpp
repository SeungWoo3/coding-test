#include <iostream>
#include <vector>
#include <queue>
#include <climits>

int main() {
    int N, M;
    std::cin >> N >> M;
    std::vector<std::vector<int>> edges(M);
    std::vector<int> distance(N+1, INT_MAX);
    for (int i = 0; i < M; i++) {
        int start, end, cost;
        std::cin >> start >> end >> cost;
        edges[i] = {start, end, cost};
    }
    std::queue<int> next_start;
    next_start.push(1);
    distance[1] = 0;
    bool is_change = false;
    for (int i = 0; i < N; i++) {
        is_change = false;
        for (int j = 0; j < next_start.size(); j++) {
            int start = next_start.front();
            next_start.pop();
            for (int k = 0; k < M; k++) {
                if (edges[k][0] == start) {
                    int end = edges[k][1];
                    int cost = edges[k][2];
                    if (distance[start] + cost < distance[end]) {
                        distance[end] = distance[start] + cost;
                        is_change = true;
                        next_start.push(end);
                    }
                }
            }
        }
        if (i == N-1 && is_change == true) {
            std::cout << -1;
            return 0;
        }
    }
    for (int i = 2; i < N+1; i++) {
        if (distance[i] == INT_MAX) {
            std::cout<<-1<<std::endl;
        }
        else {
            std::cout << distance[i] << std::endl;
        }
    }




    return 0;
}