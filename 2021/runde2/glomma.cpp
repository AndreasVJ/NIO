#include <iostream>
#include <vector>
#include <algorithm>


int main() {

    int N, K, Xg;
    std::cin >> N >> K >> Xg;

    std::vector<int> left;
    std::vector<int> right;

    for (int i = 0; i < N; i++) {
        int X;
        std::cin >> X;

        if (X > Xg) right.push_back(X);
        else left.push_back(X);
    }

    std::sort(left.begin(), left.end());
    std::sort(right.begin(), right.end());

    long long ans = 0;

    for (int i = 0; i < left.size(); i += K) {
        ans += 2*(Xg - left[i]);
    }

    for (int i = right.size() - 1; i >= 0; i -= K) {
        ans += 2*(right[i] - Xg);
    }

    std::cout << ans;

    return 0;
}