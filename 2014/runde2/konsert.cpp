#include <iostream>
#include <algorithm>
#include <vector>


// 40/100 score


int dp(std::vector<std::vector<int>>& concert, std::pair<int, int> p, int attended, int n, int maxN, int money) {
    
    if (n == maxN) return attended;

    int cost = abs(p.first - concert[n][0]) + abs(p.second - concert[n][1]) + concert[n][2];

    if (money >= cost) {
        return std::max(dp(concert, {concert[n][0], concert[n][1]}, attended + 1, n + 1, maxN, money - cost), dp(concert, p, attended, n + 1, maxN, money));
    }

    return dp(concert, p, attended, n + 1, maxN, money);
}


int main() {

    int N, T;
    std::cin >> N >> T;

    std::vector<std::vector<int>> concert(N, std::vector<int>(3));

    for (int i = 0; i < N; i++) {
        std::cin >> concert[i][0] >> concert[i][1] >> concert[i][2];
    }

    std::cout << dp(concert, {0, 0}, 0, 0, N, T);

    return 0;
}