#include <iostream>
#include <vector>
void unionSet(int x, int y);
void checkSet(int x, int y);
int findRoot(int node);

static std::vector<int> tree;

int main() {
    int N, M;
    std::cin >> N >> M;
    tree.resize(N+1,-1);

    for (int i = 0; i < M; i++) {
        int cal, x, y;
        std::cout << i << ": ";
        std::cin >> cal >> x >> y;
        
        if (cal == 0) {
            unionSet(x, y);
        }
        else {
            checkSet(x, y);
        }
        std::cout << std::endl;
    }

    return 0;
}

void unionSet(int x, int y) {
    int root_x, root_y;
    root_x = findRoot(x);
    root_y = findRoot(y);
    if (root_x < root_y) {
        tree[root_y] = root_x;
    }
    else if (root_x > root_y) {
        tree[root_x] = root_y;
    }
}

void checkSet(int x, int y) {
    if (findRoot(x) == findRoot(y)) {
        std::cout << "YES" << std::endl;
    }
    else {
        std::cout << "NO" << std::endl;
    }
}

int findRoot(int node) {
    int root;
    if (tree[node] == -1) {
        return node;
    }
    else {
        root = findRoot(tree[node]);
        return root;
    }
}