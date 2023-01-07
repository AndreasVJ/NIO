#include <iostream>
#include <algorithm>
#include <vector>


int main() {

    int N, K, youStartVotes;
    std::cin >> N >> K >> youStartVotes;

    std::vector<int> candidates(K - 1);

    for (int i = 0; i < K-1; i++) {
        std::cin >> candidates[i];
    }

    std::sort(candidates.begin(), candidates.end());

    int you = youStartVotes;
    int equalTopCandidates = 1;

    while (candidates.back() > you) {

        if (equalTopCandidates != K-1) {

            int secondTopCandidate = candidates[K - equalTopCandidates - 2];

            if (candidates.back() == secondTopCandidate) {
                equalTopCandidates++;
                continue;
            }

            else if (you + (candidates.back() - secondTopCandidate) * equalTopCandidates < secondTopCandidate) {
                int diff = candidates.back() - secondTopCandidate;
                you += diff * equalTopCandidates;
                candidates.back() -= diff;
                equalTopCandidates++;
                continue;
            }

        }

        int diff = (candidates.back() - you) / (equalTopCandidates + 1);
        candidates.back() -= diff;
        you = candidates.back();
    }

    std::cout << you - youStartVotes;

    return 0;
}