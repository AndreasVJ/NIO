#include <iostream>
#include <vector>
#include <bits/stdc++.h>

bool sortbysecdesc(const std::pair<int,int> &a, const std::pair<int,int> &b){
    return a.second > b.second;
}

int main() {

    int N, K;
    std::cin >> N >> K;

    int biggestDiscount = 0;

    std::vector<std::pair<int, int>> coupons(K);

    for (int i = 0; i < K; i++) {
        std::cin >> coupons[i].first >> coupons[i].second;
    }

    std::sort(coupons.begin(), coupons.end(), sortbysecdesc);

    // Loop through all coupons
    for (int i = 0; i < K; i++) {

        // Ignore coupons that are only valid for bigger purchases
        if (N > coupons[i].second) {

            // Create all possible combinations of coupons that doesn't make the current coupon unvalid
            std::vector<bool> possible(N - coupons[i].second + 1, false);

            // No coupons is a valid combination
            possible[0] = true;

            // Loop through all smaller coupons
            // There is no need to check the bigger coupons since they have already been checked in a previous loop
            for (int j = i; j < K; j++) {

                // Check whether there exists valid combinations without the smaller coupon
                for (int n = N - coupons[i].second; n >= 0; n--) {

                    // Add the smaller coupon if the new combination is still valid
                    if (possible[n] && n + coupons[j].first <= N - coupons[i].second) {
                        possible[n + coupons[j].first] = true;
                    }
                }
            }

            // Get the biggest possible discount
            for (int n = N - coupons[i].second; n >= 0; n--) {
                if (possible[n]) {
                    if (n > biggestDiscount) {
                        biggestDiscount = n;
                    }
                    break;
                }
            }
        }

    }

    std::cout << N - biggestDiscount;

    return 0;
}