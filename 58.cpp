#include <iostream>
#include <vector>
#include <queue>

typedef std::pair<int, int> Way;
int main() {
    int V, E, k;
    std::cin >> V >> E >> k;
    std::vector<std::vector<int>> weights(6, std::vector<int>(6, 0));
    // int weights[1001][1001];

    for (int i = 0; i < E; i++) {
        int start, end, weight;
        std::cin >> start >> end >> weight;
        weights[start][end] = weight;
    }

    std::priority_queue<Way, std::vector<Way>, std::greater<Way>> pq;
    std::vector<std::priority_queue<int>> result(V+1);

    pq.push(std::make_pair(0, 1));
    result[1].push(0);

    while (!pq.empty()) {
        Way now = pq.top();
        pq.pop();
        int pre_dist = now.first;
        int start = now.second;

        for (int end = 1; end < V+1; end++) {
            if (weights[start][end] > 0) {
                if (result[end].size() < k) {
                    result[end].push(pre_dist + weights[start][end]);
                    pq.push(std::make_pair(pre_dist + weights[start][end], end));
                }
                else if ((pre_dist + weights[start][end]) < result[end].top()){
                    result[end].pop();
                    result[end].push(pre_dist + weights[start][end]);
                    pq.push(std::make_pair(pre_dist + weights[start][end], end));
                }
            }
        }
    }

    for (int i = 1; i < V+1; i++) {
        if (result[i].size() == k) {
            std::cout << result[i].top() << std::endl;
        }
        else {
            std::cout << -1 << std::endl;
        }
    }




    return 0;
}