#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>


long long getLength(int node, std::vector<std::vector<std::pair<int, long long>>>& edges, std::vector<long long>& maxLength) {
    
    if (maxLength[node] != 0) {
        return maxLength[node];
    }
    
    if (edges[node].size() == 0) {
        return 0;
    }

    for (std::pair<int, long long>& e : edges[node]) {
        maxLength[node] = std::max(maxLength[node], getLength(e.first, edges, maxLength) + e.second);
    }

    return maxLength[node];
}


int main() {

    int N, M;
    std::cin >> N >> M;

    std::vector<std::vector<std::pair<int, long long>>> edges(N);
    std::vector<long long> maxLength(N);

    for (int i = 0; i < M; i++) {
        int U, V, L;
        std::cin >> U >> V >> L;
        edges[U - 1].push_back({V - 1, L});
    }

    long long ans = 0;

    for (int i = 0; i < N; i++) {
        if (maxLength[i] == 0) {
            ans = std::max(ans, getLength(i, edges, maxLength));
        }
    }

    std::cout << ans;

    return 0;
}