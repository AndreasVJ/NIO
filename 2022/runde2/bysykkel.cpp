#include <iostream>
#include <limits>
#include <vector>
#include <queue>
#include <cmath>
#include <algorithm>

int main() {

    int N;
    std::cin >> N;

    std::vector<std::vector<double>> height(N, std::vector<double>(N));
    std::vector<std::vector<char>> grid(N, std::vector<char>(N));

    for (int y = 0; y < N; y++) {
        for (int x = 0; x < N; x++) {
            std::cin >> height[y][x];
        }
    }

    for (int y = 0; y < N; y++) {
        for (int x = 0; x < N; x++) {
            std::cin >> grid[y][x];
        }
    }

    std::vector<std::vector<std::vector<double>>> minDistance(N, std::vector<std::vector<double>>(N, std::vector<double>(2, std::numeric_limits<double>::max())));
    minDistance[0][0][0] = 0;

    struct node {
        int x;
        int y;
        bool bicycle;
        double distance;
        bool operator()(node& a, node& b) {
            return a.distance > b.distance;
        }
    };

    std::priority_queue<node, std::vector<node>, node> pq;
    pq.push({0, 0, 0, 0});

    int directions[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    while (pq.top().x != N - 1 || pq.top().y != N - 1 || (pq.top().bicycle && (grid.back().back() != '*' && grid.back().back() != 'T'))) {
        
        int x = pq.top().x;
        int y = pq.top().y;
        bool bicycle = pq.top().bicycle;
        double distance = pq.top().distance;

        pq.pop();

        for (int i = 0; i < 4; i++) {

            int x2 = x + directions[i][0];
            int y2 = y + directions[i][1];

            if (0 <= x2 && x2 < N && 0 <= y2 && y2 < N) {

                double bicycleDistance = distance + 10 * pow(2, (height[y2][x2] - height[y][x]) / 100);
                double walkDistance = distance + 50;

                if (bicycleDistance < minDistance[y2][x2][1]) {
                    switch (grid[y][x]) {
                        case 'X':
                            if (bicycle) {
                                pq.push({x2, y2, 1, bicycleDistance});
                                minDistance[y2][x2][1] = bicycleDistance;
                            }
                            break;
                        
                        case 'F':
                            pq.push({x2, y2, 1, bicycleDistance});
                            minDistance[y2][x2][1] = bicycleDistance;
                            break;
                        
                        case 'T':
                            if (bicycle) {
                                pq.push({x2, y2, 1, bicycleDistance});
                                minDistance[y2][x2][1] = bicycleDistance;
                            }
                            break;

                        case '*':
                            pq.push({x2, y2, 1, bicycleDistance});
                            minDistance[y2][x2][1] = bicycleDistance;
                            break;
                    }
                }
                
                if (walkDistance < minDistance[y2][x2][0]) {
                    switch (grid[y][x]) {
                        case 'X':
                            if (!bicycle) {
                                pq.push({x2, y2, 0, walkDistance});
                                minDistance[y2][x2][0] = walkDistance;
                            }
                            break;
                        
                        case 'F':
                            if (!bicycle) {
                                pq.push({x2, y2, 0, walkDistance});
                                minDistance[y2][x2][0] = walkDistance;
                            }
                            break;
                        
                        case 'T':
                            pq.push({x2, y2, 0, walkDistance});
                            minDistance[y2][x2][0] = walkDistance;
                            break;

                        case '*':
                            pq.push({x2, y2, 0, walkDistance});
                            minDistance[y2][x2][0] = walkDistance;
                            break;
                    }
                }
            }
        }
    }

    std::cout << pq.top().distance;

    return 0;
}