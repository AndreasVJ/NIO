#include <iostream>
#include <unordered_map>
#include <vector>
#include <stack>


// 32/100


int main() {

    int N, V;
    std::cin >> N >> V;

    std::vector<std::vector<int>> column(V);
    std::vector<int> row;

    int maxH = 0;

    for (int X, B, h, i = 0; i < N; i++) {

        std::cin >> X >> B;

        h = 0;

        for (int j = X; j < X + B; j++) {
            if (!column[j].empty() && column[j].back() >= h) {
                h = column[j].back() + 1;
            }
        }

        for (int j = X; j < X + B; j++) {
            column[j].push_back(h);
        }

        if (h > maxH) maxH++;

        if (h == row.size()) row.push_back(B);
        else row[h] += B;

        if (row[h] == V) {

            maxH--;

            row.erase(row.begin() + h);

            for (int k, j = 0; j < V; j++) {

                k = column[j].size() - 1;
                for (int b = column[j].size() / 2; b > 0; b /= 2) {
                    while (k - b >= 0 && column[j][k - b] >= h) k -= b;
                }

                for (int n = k; n < column[j].size() - 1; n++) {
                    column[j][n] = column[j][n + 1] - 1;
                }

                column[j].pop_back();
            }

        }

        std::cout << maxH + 1 << "\n";

    }

    return 0;
}