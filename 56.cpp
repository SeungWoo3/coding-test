#include <vector>
#include <iostream>
#include <climits>

int main() {
    std::cout << INT_MAX;
    int V, E, start;
    std::cin >> V >> E >> start;
    std::vector<std::vector<int>> edges(E);
    for (int i = 0; i < E; i++) {
        int u, v, w;
        std::cin >> u >> v >> w;
        edges[i] = {u, v, w};
    }
    
    std::vector<int> distance(V+1, -1);
    std::vector<int> visit(V+1, 0);
    distance[start] = 0;
    for (int _ = 1; _ < V+1; _++) {

        // 노드 방문
        visit[start] = 1;

        // 인접 노드 거리 갱신
        for (int edge = 0; edge < E; edge++) {
            if (edges[edge][0] == start) {
                int end = edges[edge][1];
                if (distance[end] > distance[start] + edges[edge][2] || distance[end] == -1) {
                    distance[end] = distance[start] + edges[edge][2];
                };
            }
        }

        for (int i = 1; i < V+1; i++) {
        }

        // 다음 시작점 찾기
        int min = -1;
        int min_idx = 0;
        for(int node = 1; node < V+1; node++) {
            if (visit[node] == 0) {
                if (min == -1) {
                    min = distance[node];
                    min_idx = node;
                }
                else if (distance[node] != -1) {
                    if (min > distance[node]) {
                        min = distance[node];
                        min_idx = node;
                    }
                }
            }
        }
        start = min_idx;
    }

    for (int i = 1; i < V+1; i++) {
        if (distance[i] == -1) {
            std::cout << "INF" << std::endl;
        }
        else {
            std::cout << distance[i] << std::endl;
        }
    }

    return 0;
}