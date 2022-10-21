#include <iostream>


int main() {

    int N;
    std::cin >> N;

    for (int i = 0; i < N; i++) {
        long long a, b;
        char op;
        std::cin >> a >> op >> b;

        if (op == '+') {
            std::cout << a + b << "\n";
        }
        else if (op == '-') {
            std::cout << a - b << "\n";
        }
        else {
            std::cout << a * b << "\n";
        }
    }

    return 0;
}