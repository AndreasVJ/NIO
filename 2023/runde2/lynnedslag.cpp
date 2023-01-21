#include <iostream>
#include <queue>
#include <vector>


int main() {

    int N, K;
    std::cin >> N >> K;

    std::priority_queue<int, std::vector<int>, std::greater<int>> q;

    for (int i = 0; i < K; i++) {
        int a, b;
        std::cin >> a >> b;
        q.push(a);
        q.push(b+1);
    }

    int ans = 0;
    int pos = 0;
    bool flipped = false;

    while (!q.empty() && q.top() != N) {
        if (!flipped) {
            ans += q.top() - pos;
        }
        flipped = !flipped;
        pos = q.top();
        q.pop();
    }

    if (!flipped) {
        ans += N - pos;
    }

    std::cout << ans;

    return 0;
}