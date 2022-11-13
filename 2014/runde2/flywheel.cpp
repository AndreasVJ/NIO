#include <iostream>

int main() {

    int n, p_i, prev;
    std::cin >> n >> prev;

    int profit = 0;

    for (int i = 1; i < n; i++) {
        std::cin >> p_i;
        if (p_i > prev) {
            profit += p_i-prev;
        }
        prev = p_i;
    }

    if (p_i < 0) profit -= p_i;

    std::cout << profit * 1000 << "\n";

    return 0;
}