#include <iostream>
#include <algorithm>


int main() {

    int K, N;
    std::cin >> K >> N;

    int ans = 0;
    int num = 0;
    int min = 0;
    int max = 0;

    int prev = -K;

    for (int i = 0; i < N; i++) {
        int T;
        std::cin >> T;

        num += T;
        min = std::min(min, num);
        max = std::max(max, num);

        if (max - min > K || min < -K - prev || max > K - prev) {
            ans++;
            num = 0;
            min = 0;
            max = 0;
            prev = T;
        }
    }

    std::cout << ans;

    return 0;
}