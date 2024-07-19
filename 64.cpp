#include <iostream>
#include <queue>
#include <vector>
#include <climits>

int main() {
    int V, E;
    std::cin >> V >> E;

    typedef struct Edge{
        int start, end, cost;
        bool operator > (const Edge &temp) const {
            return cost > temp.cost;
        }
    }Edge;

    std::priority_queue<Edge, std::vector<Edge>, std::greater<Edge>> pq;
    for (int i = 0; i < E; i++) {
        int start, end, cost;
        std::cin >> start >> end >> cost;
        pq.push(Edge{start, end, cost});
    }

    std::vector<int> root(V+1);
    for (int i = 1; i < V+1; i++) {
        root[i] = i;
    }
    int num_edge = 0;
    int result = 0;

    while(num_edge < V-1) {
        Edge edge = pq.top();
        pq.pop();
        if (root[edge.start] > root[edge.end]) {
            root[edge.start] = root[edge.end];
            num_edge ++;
            result += edge.cost;
        }
        else if (root[edge.start] < root[edge.end]) {
            root[edge.end] > root[edge.start];
            num_edge ++;
            result += edge.cost;
        }
    }
    std::cout << result;

    return 0;
}