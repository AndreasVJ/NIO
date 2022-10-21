#include <iostream>

int main() {

    int N;
    std::cin >> N;

    N = N%31;

    int S = 1 << N/2;

    if (N%2) {
        S += 2;
    }

    int a = (1 << (N-1)) + S/2 - 1;

    std::cout << a%1000000007 << "\n";

    return 0;
}