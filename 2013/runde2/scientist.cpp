#include <iostream>
#include <bits/stdc++.h> 


int main() {

    int N;
    std::cin >> N;

    std::vector<long long> R(N);

    for (int i = 0; i < N; i++) {
        std::cin >> R[i];
    }

    std::sort(R.begin(), R.end(), std::greater<long long>());

    int i = 3;

    while (i < N && R[2] != R[1]) {
        if (R[i] >= R[1]-R[2]) {
            R[i] -= R[1]-R[2];
            R[2] = R[1];
        }
        else {
            R[2] += R[i];
            i++;
        }
    }

    while (i < N && R[1] != R[0]) {
        if (R[i] >= 2*(R[0]-R[1])) {
            R[i] -= 2*(R[0]-R[1]);
            R[1] = R[0];
            R[2] = R[0];
        }
        else {
            if (i < N-1) R[i+1] += R[i]%2;
            R[1] += R[i]/2;
            R[2] += R[i]/2;
            i++;
        }
    }

    long long sum = 0;
    while (i < N) {
        sum += R[i];
        i++;
    }
    
    std::cout << R[2] + sum/3;

    return 0;
}