#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>

static int N, M, V;
static std::vector<std::vector<int>> edge;
static std::vector<int> visit;
void DFS(int start);
void BFS(int start);

int main() {
    std::cin >> N >> M >> V;
    edge.resize(N+1);
    visit.resize(N+1);
    
    for (int i = 0; i < M; i++) {
        int start, end;
        std::cin >> start >> end;
        edge[start].push_back(end);
        edge[end].push_back(start);
    }
    
    for (int i = 0; i < N; i++){
        std::sort(edge[i].begin(), edge[i].end());
    }

    std::fill(visit.begin(), visit.end(), false);
    DFS(V);
    std::cout << std::endl;
    std::fill(visit.begin(), visit.end(), false);
    BFS(V);
    return 0;
}

void DFS(int start) {
    visit[start] = true;
    std::cout << start << " ";
    for(int node: edge[start]){
        if (!visit[node]){
            DFS(node);
        }
    }
}

void BFS(int start) {
    std::queue<int> que;
    que.push(start);
    visit[start] = true;
    while (que.empty() == false) {
        int node = que.front();
        que.pop();
        std::cout << node << " ";
        for (int new_node: edge[node]){
            if (visit[new_node] == false) {
                visit[new_node] = true;
                que.push(new_node);
            }
        }
    }
    std::cout << std::endl;
}