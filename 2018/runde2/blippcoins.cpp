#include <iostream>
#include <queue>


int main() {

    int N, K;
    std::cin >> N >> K;

    int BlippCoins = 0;

    std::queue<int> prices;

    for (int i = 0; i < N; i++) {
        int Pi;
        std::cin >> Pi;

        // Calculate when to buy and when to sell
        if (i > 0) {
            if (Pi > prices.back() && K > prices.back() && BlippCoins == 0) {
                // Buy
                BlippCoins = K / prices.back();
                K -= BlippCoins*prices.back();
            }
            else if (Pi < prices.back() && BlippCoins > 0) {
                // Sell
                K += BlippCoins*prices.back();
                BlippCoins = 0;
            }

        }

        prices.push(Pi);

    }

    // Sell the remaining BlippCoins
    if (BlippCoins > 0) {
        K += BlippCoins*prices.back();
    }

    std::cout << K << "\n";

    return 0;
}