#include <iostream>
#include <vector>
#include <queue>


int main() {

    int N;
    std::cin >> N;

    struct Triplet {
        int value[3];
    };

    // The program is simpler when not using index 0 of vectors because the levels are numbered 1 to N

    std::vector<Triplet> level(N+1);
    for (int i = 1; i < N; i++) {
        std::cin >> level[i].value[0] >> level[i].value[1] >> level[i].value[2];
    }

    std::vector<bool> visited(N+1, false);
    std::vector<int> distance(N+1);

    visited[1] = true;
    distance[1] = 1;

    std::queue<int> searchQueue;
    searchQueue.push(1);

    // Breadth first search
    while (searchQueue.front() != N) {

        // Add levels from warpzone to queue
        for (int i = 0; i < 3; i++) {
            if (!visited[level[searchQueue.front()].value[i]]) {
                searchQueue.push(level[searchQueue.front()].value[i]);
                distance[level[searchQueue.front()].value[i]] = distance[searchQueue.front()] + 1;
                visited[level[searchQueue.front()].value[i]] = true;
            }
        }

        // Add next level to queue
        if (!visited[searchQueue.front() + 1]) {
            searchQueue.push(searchQueue.front() + 1);
            distance[searchQueue.front() + 1] = distance[searchQueue.front()] + 1;
            visited[searchQueue.front() + 1] = true;
        }

        searchQueue.pop();

    }

    std::cout << distance[N];

    return 0;
}