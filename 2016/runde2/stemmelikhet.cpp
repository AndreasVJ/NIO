#include <iostream>
#include <vector>
#include <string>

int main() {

    std::string output;

    int N, M, F, Ai, Fi;
    std::cin >> N >> M;

    std::vector<int> stocks;

    for (int i = 0; i < M; i++) {
        std::cin >> Ai;
        stocks.push_back(Ai);
    }

    std::cin >> F;

    for (int i = 0; i < F; i++) {

        std::cin >> Fi;

        std::vector<bool> possible(N+1, false);
        possible[0] = true;

        for (int a = 0; a < M; a++) {
           if (a != Fi) {
            for (int j = N; j >= 0; j--) {
                if (possible[j] && j + stocks[a] <= N) {
                    possible[j + stocks[a]] = true;
                }
            }
           }
        }

        output = "NEI";

        for (int j = 0; j <= N-stocks[Fi]; j++) {
            if (possible[j] && possible[j + stocks[Fi]]) {
                output = "JA";
                break;
            }
        }

        std::cout << output << "\n";

    }

    return 0;
}