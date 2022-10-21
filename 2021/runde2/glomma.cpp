#include <iostream>
#include <vector>
#include <bits/stdc++.h>

// Messy code :(

int main() {

    int N, K, Xg;
    std::cin >> N >> K >> Xg;

    int distanceTraveled = 0;

    std::vector<int> X(N);
    std::vector<int> negX;

    for (int i = 0; i < N; i++) {
        int Xi;
        std::cin >> Xi;
        X[i] = Xi - Xg;
    }

    sort(X.begin(), X.end());


    while (X.size() && X.front() < 0) {
        negX.insert(negX.begin(), -X.front());
        X.erase(X.begin());
    }

    int packages = 1;

    for (int i = 0; i < negX.size(); i++) {
        if (i == 0) {
            if (packages == K) {
                distanceTraveled += 2*negX[i];
                packages = 0;
            }
            else {
                distanceTraveled += negX[i];
            }
        }
        else if (packages == K) {
            if (K > 1) {
                distanceTraveled += 2*negX[i] - negX[i-1];
            }
            else {
                distanceTraveled += 2*negX[i];
            }
            packages = 0;
        }
        else if (packages == 1) {
            distanceTraveled += negX[i];
        }
        else {
            distanceTraveled += negX[i] - negX[i-1];
        }
        packages++;
    }

    if (packages != 1) {
        distanceTraveled += negX.back();
    }

    packages = 1;

    for (int i = 0; i < X.size(); i++) {
        if (i == 0) {
            if (packages == K) {
                distanceTraveled += 2*X[i];
                packages = 0;
            }
            else {
                distanceTraveled += X[i];
            }
        }
        else if (packages == K) {
            if (K > 1) {
                distanceTraveled += 2*X[i] - X[i-1];
            }
            else {
                distanceTraveled += 2*X[i];
            }
            packages = 0;
        }
        else if (packages == 1) {
            distanceTraveled += X[i];
        }
        else {
            distanceTraveled += X[i] - X[i-1];
        }
        packages++;
    }

    if (packages != 1) {
        distanceTraveled += X.back();
    }

    std::cout << distanceTraveled << "\n";

    return 0;
}