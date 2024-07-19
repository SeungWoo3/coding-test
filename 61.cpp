#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

int main() {
    int n, m;
    std::cin >> n >> m;
    std::vector<std::vector<int>> distance(n+1, std::vector<int>(n+1, INT_MAX/2));
    for (int i = 1; i < n+1; i++) {
        distance[i][i] = 0;
    }
    for (int i = 0; i < m; i++) {
        int start, end, cost;
        std::cin >> start >> end >> cost;
        distance[start][end] = std::min(distance[start][end], cost);
    }



    for (int k = 1; k < n+1; k++) {
        for (int start = 1; start < n+1; start++) {
            for (int end = 1; end < n+1; end++) {
                distance[start][end] = std::min(distance[start][end], distance[start][k] + distance[k][end]);
            }
        }
    }

    for (int start = 1; start < n+1; start++) {
        for (int end = 1; end < n+1; end++) {
            if (distance[start][end] == INT_MAX/2) {
                distance[start][end] = -1;
            }
            std::cout << distance[start][end] << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}