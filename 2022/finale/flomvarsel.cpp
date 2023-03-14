#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <algorithm>


struct node {
    int x, y, h;
    bool operator()(node a, node b) {
        return a.h > b.h;
    }
};


int main() {

    int L, B;
    std::cin >> L >> B;

    std::vector<std::vector<int>> h(L, std::vector<int>(B));
    std::vector<std::vector<int>> w(L, std::vector<int>(B, INT_MAX));
    std::vector<std::vector<bool>> visited(L, std::vector<bool>(B));

    std::priority_queue<node, std::vector<node>, node> pq;

    for (int y = 0; y < L; y++) {
        for (int x = 0; x < B; x++) {
            std::cin >> h[y][x];
        }
    }

    for (int y = 0; y < L; y++) {
        for (int x = 0; x < B; x++) {
            int a;
            std::cin >> a;
            if (a) {
                w[y][x] = h[y][x];
                pq.push({x, y, w[y][x]});
                visited[y][x] = true;
            }
        }
    }

    int dirs[4][2] = {{0, 1}, {-1, 0}, {0, -1}, {1, 0}};

    while (!pq.empty()) {
        int x = pq.top().x;
        int y = pq.top().y;
        int height = pq.top().h;
        pq.pop();

        for (auto dir : dirs) {
            int x2 = x + dir[0];
            int y2 = y + dir[1];

            if (0 <= x2 && x2 < B && 0 <= y2 && y2 < L) {
                if (!visited[y2][x2]) {
                    w[y2][x2] = std::max(w[y][x], h[y2][x2]);
                    visited[y2][x2] = true;
                    pq.push({x2, y2, w[y2][x2]});
                }
            }
        }
    }

    int ans = 0;

    for (int y = 0; y < L; y++) {
        for (int x = 0; x < B; x++) {
            if (w[y][x] > h[y][x]) ans++;
        }
    }

    std::cout << ans;

    return 0;
}