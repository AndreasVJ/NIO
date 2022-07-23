#include <iostream>
#include <vector>


int main() {

    int N, T;
    std::cin >> N;

    long long sum = 0;
    int transactionsRemoved = 0;

    std::vector<int> negativeTransactions;

    for (int i = 0; i < N; i++) {

        std::cin >> T;
        sum += T;

        if (T < 0) {

            // Sort the negative transactions in increasing order using binary search

            // The binary search doesn't work on an empty vector
            if (negativeTransactions.size() == 0) {
                negativeTransactions.push_back(T);
            }
            else {

                int searchBottom = 0;
                int searchTop = negativeTransactions.size()-1;

                while (true) {
                    
                    int middle = (searchBottom + searchTop) / 2;

                    if (T > negativeTransactions[middle]) {
                        searchBottom = middle;
                    }
                    else if (T < negativeTransactions[middle]) {
                        searchTop = middle;
                    }
                    else {
                        negativeTransactions.insert(negativeTransactions.begin() + middle, T);
                        break;
                    }

                    if (searchTop - searchBottom <= 1) {
                        if (T < negativeTransactions[searchBottom]) {
                            negativeTransactions.insert(negativeTransactions.begin() + searchBottom, T);
                        }
                        else if (T > negativeTransactions[searchTop]) {
                            negativeTransactions.insert(negativeTransactions.begin() + searchTop + 1, T);
                        }
                        else {
                            negativeTransactions.insert(negativeTransactions.begin() + searchTop, T);
                        }
                        break;
                    }
                }

            }

            // Remove the biggest negative transactions when the sum goes under 0
            while (sum < 0) {
                sum -= negativeTransactions[0];
                negativeTransactions.erase(negativeTransactions.begin());
                transactionsRemoved++;
            }

        }
    }

    std::cout << transactionsRemoved;

    return 0;
}