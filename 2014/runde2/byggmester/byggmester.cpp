#include <iostream>
#include <vector>
#include <bits/stdc++.h>
#include <algorithm>

int main() {

    int N, T;
    std::cin >> N >> T;

    std::vector<int> p(N);
    std::vector<int> o(T);

    for (int i = 0; i < N; i++) {
        std::cin >> p[i];
    }

    sort(p.begin(), p.end());

    int a, searchBottom, searchTop, middle;
    for (int i = 0; i < T; i++) {
        std::cin >> a;

        searchBottom = 0;
        searchTop = N-1;

        while (1) {
            middle = (searchBottom + searchTop) / 2;

            if (a > p[middle]) {
                searchBottom = middle;
            }
            else if (a < p[middle]) {
                searchTop = middle;
            }
            else {
                o[i] = 0;
                break;
            }

            if (searchTop - searchBottom == 1) {
                o[i] = std::min({abs(p[searchTop] - a), abs(a - p[searchBottom])});
                break;
            }
        }
    }

    for (int i = 0; i < o.size(); i++) {
        std::cout << o[i] << "\n";
    }

    return 0;
}