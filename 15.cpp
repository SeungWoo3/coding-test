#include <iostream>
#include <vector>

static std::vector<std::vector<int>> edge;
static std::vector<bool> visit = {false};
void search(int v);

int main() {
    int N, M;
    std::cin >> N;
    std::cin >> M;
    edge.resize(N+1);
    for (int i = 0; i < M; i++) {
        int start, end;
        std::cin >> start;
        std::cin >> end;
        edge[start].push_back(end);
        edge[end].push_back(start);
    }
    int cnt = 0;
    for (int i = 1; i < N; i++) {
        if (visit[i] == false) {
            cnt += 1;
            search(i);
        }
    }
    std::cout << cnt;
    return 0;
}

void search(int node) {
    visit[node] = true;
    for (int i : edge[node]) {
        if (visit[i] == false) {
            search(i);
        }
    }
}
