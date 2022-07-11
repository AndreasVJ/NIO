#include <iostream>
#include <vector>
#include <queue>


int main() {

    int N, M;
    std::cin >> N >> M;
    
    int ferriesNeeded = 0;

    std::vector<std::vector<int>> connections;
    std::vector<bool> visited(N, false);
    std::queue<int> islandQueue;

    for (int i = 0; i < N; i++) {
        connections.push_back({});
    }

    for (int i = 0; i < M; i++) {
        int xi, yi;
        std::cin >> xi >> yi;
        connections.at(xi).push_back(yi);
        connections.at(yi).push_back(xi);
    }

    for (int i = 0; i < N; i++) {
        if (visited[i] == false) {

            islandQueue.push(i);

            while (islandQueue.size() > 0) {

                int island = islandQueue.front();

                std::vector<int> neighbours = connections.at(island);
                visited[island] = true;

                for (auto i = neighbours.begin(); i != neighbours.end(); i++) {
                    if (visited[*i] == false) {
                        islandQueue.push(*i);
                    }
                }

                islandQueue.pop();
            }

            ferriesNeeded++;
        }
    }

    ferriesNeeded--;

    std::cout << ferriesNeeded << std::endl;

    return 0;
}