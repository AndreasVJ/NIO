#include <iostream>
#include <string>
#include <vector>
#include <cmath>


int main(){

    int width, height;
    std::cin >> width >> height;

    int end[2];

    std::vector<std::string> hyperionMap;

    // Direction vectors for up, right, down and left
    int directions[4][2] = {{0, -1}, {1, 0}, {0, 1}, {-1, 0}};

    struct node {
        int position[2];
        int direction;
        int distance;
    };

    // startNode has direction north
    node startNode;
    startNode.direction = 0;
    startNode.distance = 0;

    
    for (int i = 0; i < height; i++) {
        std::string line;
        std::cin >> line;
        if (line.find('S') != std::string::npos) {
            startNode.position[0] = line.find('S');
            startNode.position[1] = i;
        }
        if (line.find('M') != std::string::npos) {
            end[0] = line.find('M');
            end[1] = i;
        }
        hyperionMap.push_back(line);
    }

    std::vector<node> queue;
    queue.push_back(startNode);

    while (queue[0].position[0] != end[0] || queue[0].position[1] != end[1]) {

        // Check all 4 neighbours
        for (int i = 0; i < 4; i++) {

            int x = queue[0].position[0] + directions[i][0];
            int y = queue[0].position[1] + directions[i][1];

            if (x >= 0 && y >= 0 && x < width && y < height) {
                if (hyperionMap[y][x] == '.' || hyperionMap[y][x] == 'M') {

                    // Make node unavailable to prevent backtracking
                    hyperionMap[y][x] = '#';

                    node newNode;
                    newNode.position[0] = x;
                    newNode.position[1] = y;
                    newNode.direction = i;
                    int cost = abs(i - queue[0].direction) + 1;
                    if (cost == 4) {
                        cost = 2;
                    }
                    newNode.distance = queue[0].distance + cost;

                    // Place node in queue
                    for (int i = 0; i < queue.size()+1; i++) {
                        if (i == queue.size()) {
                            queue.push_back(newNode);
                            break;
                        }
                        if (queue[i].distance > newNode.distance) {
                            queue.insert(queue.begin() + i, newNode);
                            break;
                        }
                    }
                }
            }
        }
        // Remove node when all neighbours have been checked
        queue.erase(queue.begin());
    }

    std::cout << queue[0].distance << std::endl;

    return 0;
}