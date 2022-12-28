#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>


int main() {

    int N;
    std::cin >> N;

    std::vector<std::vector<int>> friends(N);

    for (int K, i = 0; i < N; i++) {
        
        std::cin >> K;
        friends[i].resize(K);

        for (int j = 0; j < K; j++) {
            std::cin >> friends[i][j];
        }
    }

    int ans = 0;

    std::vector<int> gift(N);

    std::queue<int> q;

    for (int i = 0; i < friends.size(); i++) {
        if (gift[i] == 0) {
        
            int numGift[2] = {1, 0};

            q.push(i);
            gift[i] = 1;

            while (!q.empty()) {

                int curr = q.front();
                q.pop();

                for (int person : friends[curr]) {

                    if (gift[person] == 0) {
                        gift[person] = gift[curr]%2 + 1;
                        numGift[gift[person] - 1]++;
                        q.push(person);
                    }
                    
                    else if (gift[curr] == gift[person]) {
                        std::cout << 0;
                        return 0;
                    }
                }
            }

            ans += std::max(numGift[0], numGift[1]);
        }
    }

    std::cout << ans;

    return 0;
}