#include <iostream>
#include <vector>


long long dp(int day, int city, int N, std::vector<std::pair<long long, long long>>& price, std::vector<std::vector<long long>>& cache) {

    if (day >= N) {
        return 0;
    }

    if (cache[day][city] != -1) {
        return cache[day][city];
    }

    // Kristiansand
    if (city == 0) {
        return cache[day][city] = std::max(dp(day+3, 1, N, price, cache), dp(day+2, 2, N, price, cache));
    }

    // Bergen
    if (city == 1) {
        return cache[day][city] = std::max(dp(day+3, 0, N, price, cache) + price[day].first, dp(day+1, 1, N, price, cache));
    }

    // Oslo
    return cache[day][city] = std::max(dp(day+2, 0, N, price, cache) + price[day].second, dp(day+1, 2, N, price, cache));
}


int main() {

    int N;
    std::cin >> N;

    std::vector<std::pair<long long, long long>> price(N);
    for (int i = 0; i < N; i++) {
        std::cin >> price[i].first >> price[i].second;
    }

    std::vector<std::vector<long long>> cache(N, std::vector<long long>(3, -1));

    std::cout << dp(0, 0, N, price, cache);

    return 0;
}