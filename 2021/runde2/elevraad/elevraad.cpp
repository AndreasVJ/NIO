#include <iostream>
#include <vector>


int main() {

    int N, K, actuallyYou;
    std::cin >> N >> K >> actuallyYou;

    std::vector<int> candidates;
    int candidate;

    int you = actuallyYou;

    for (int i = 0; i < K-1; i++) {
        
        std::cin >> candidate;

        // Sort the candidates in increasing order using binary search

        // The binary search doesn't work on an empty vector
        if (candidates.size() == 0) {
            candidates.push_back(candidate);
        }
        else {

            int searchBottom = 0;
            int searchTop = candidates.size()-1;

            while (true) {
                
                int middle = (searchBottom + searchTop) / 2;

                if (candidate > candidates[middle]) {
                    searchBottom = middle;
                }
                else if (candidate < candidates[middle]) {
                    searchTop = middle;
                }
                else {
                    candidates.insert(candidates.begin() + middle, candidate);
                    break;
                }

                if (searchTop - searchBottom <= 1) {
                    if (candidate < candidates[searchBottom]) {
                        candidates.insert(candidates.begin() + searchBottom, candidate);
                    }
                    else if (candidate > candidates[searchTop]) {
                        candidates.insert(candidates.begin() + searchTop + 1, candidate);
                    }
                    else {
                        candidates.insert(candidates.begin() + searchTop, candidate);
                    }
                    break;
                }
            }
        }
    }

    int equalTopVotes = 1;

    while (candidates.back() > you) {

        if (equalTopVotes == candidates.size()) {
            int diff = ((candidates.back() - you)/(1+equalTopVotes));
            you += diff * equalTopVotes;
            candidates.back() -= diff;
            you += candidates.back() - you;
            candidates.back()--;
        }

        else if (candidates.back() == candidates[candidates.size()-equalTopVotes-1]) {
            equalTopVotes++;
        }
        else if (you + (candidates.back() - candidates[candidates.size()-equalTopVotes-1]) * equalTopVotes < candidates[candidates.size()-equalTopVotes-1]) {
            int diff = (candidates.back() - candidates[candidates.size()-equalTopVotes-1]);
            you += diff * equalTopVotes;
            candidates.back() -= diff;
            equalTopVotes++;
        }
        else {
            int diff = ((candidates.back() - you)/(1+equalTopVotes));
            you += diff * equalTopVotes;
            candidates.back() -= diff;
            you += candidates.back() - you;
            candidates.back()--;
        }
    }

    std::cout << you - actuallyYou;

    return 0;
}