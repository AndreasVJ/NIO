#include <iostream>

int main() {

    int n;
    std::cin >> n;

    int profit = 0;

    bool hasBought = false;

    int buyPrice, previousPrice;

    for (int i = 0; i < n; i++) {
        int pi;
        std::cin >> pi;

        // Calculate when to buy and when to sell
        if (i > 0) {
            if (pi > previousPrice && !hasBought) {
                // Buy
                buyPrice = previousPrice;
                hasBought = true;
            }
            else if (pi < previousPrice && hasBought) {
                // Sell
                profit += previousPrice - buyPrice;
                hasBought = false;
            }
        }

        previousPrice = pi;

    }

    // Sell the remaining power
    if (hasBought) {
        // Don't sell if the sell price is negative
        if (previousPrice < 0) {
            profit -= buyPrice;
        }
        else {
            profit += previousPrice - buyPrice;
        }
    }
    else if (previousPrice < 0) {
        // Buy the last power if you have no power left and the price is negative
        profit -= previousPrice;
    }

    std::cout << profit * 1000 << "\n";

    return 0;
}