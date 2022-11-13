#include <iostream>

int main() {

    int n, t;
    std::cin >> n;

    for (int i = 0; i < n; i++) {
        std::cin >> t;
        if (t%2) std::cout << "GALT\n";
        else std::cout << "RIKTIG\n";
    }

    return 0;
}