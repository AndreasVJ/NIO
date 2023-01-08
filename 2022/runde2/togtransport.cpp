#include <iostream>
#include <vector>


int dp(int start, int end, int tracks, std::vector<std::vector<std::pair<int, int>>>& connections, std::vector<std::vector<std::vector<int>>>& cache) {

    if (tracks == 0 || end == cache.size() - 1) {
        return 0;
    }

    if (cache[start][end][tracks] != -1) {
        return cache[start][end][tracks];
    }

    int money = 0;
    for (std::pair<int, int> node : connections[end + 1]) {
        if (start <= node.first && node.first < end + 1) {
            money += node.second;
        }
    }

    return cache[start][end][tracks] = std::max(dp(end+1, end+1, tracks, connections, cache), dp(start, end+1, tracks-1, connections, cache) + money);
}


int main() {

    int N, T, K;
    std::cin >> N >> T >> K;

    std::vector<std::vector<std::pair<int, int>>> connections(N);

    for (int i = 0; i < K; i++) {
        int A, B, P;
        std::cin >> A >> B >> P;
        if (A > B) {
            connections[A].push_back({B, P});
        }
        else {
            connections[B].push_back({A, P});
        }
    }

    std::vector<std::vector<std::vector<int>>> cache(N, std::vector<std::vector<int>>(N, std::vector<int>(T+1, -1)));

    std::cout << dp(0, 0, T, connections, cache);

    return 0;
}