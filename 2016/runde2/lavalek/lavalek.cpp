#include <iostream>
#include <map>
#include <queue>


int main(){
    
    int B, L, S;
    std::cin >> B >> L >> S;

    std::map<int, bool> stoneMap;

    struct stone {
        int pos;
        int dis;
    };

    std::queue<stone> stoneQueue;


    for (int i = 0; i < S; i++) {
        int x, y;
        std::cin >> y >> x;

        if (y == 0) {
            stone startStone;
            startStone.pos = L*y + x;
            startStone.dis = 1;
            stoneQueue.push(startStone);
        }
        else {
            stoneMap.insert({L*y + x, false});
        }

    }


    while (stoneQueue.front().pos < L*(B-1)) {

        int pos = stoneQueue.front().pos;
        int dis = stoneQueue.front().dis;


        stone newStone;
        newStone.dis = dis + 1;

        // Up
        if (stoneMap.find(pos - L) != stoneMap.end()) {
            if (!stoneMap[pos - L]) {

                newStone.pos = pos - L;
                stoneQueue.push(newStone);

                stoneMap[pos - L] = true;
            }
        }
        
        // Right
        if (pos%L + 1 < L) {
            if (stoneMap.find(pos + 1) != stoneMap.end()) {
                if (!stoneMap[pos + 1]) {

                    newStone.pos = pos + 1;
                    stoneQueue.push(newStone);

                    stoneMap[pos + 1] = true;
                }
            }
        }

        // Down
        if (stoneMap.find(pos + L) != stoneMap.end()) {
            if (!stoneMap[pos + L]) {

                newStone.pos = pos + L;
                stoneQueue.push(newStone);

                stoneMap[pos + L] = true;
            }
        }
        
        // Left
        if (pos%L - 1 >= 0) {
            if (stoneMap.find(pos - 1) != stoneMap.end()) {
                if (!stoneMap[pos - 1]) {

                    newStone.pos = pos - 1;
                    stoneQueue.push(newStone);

                    stoneMap[pos - 1] = true;
                }
            }
        }

        stoneQueue.pop();
    }

    std::cout << stoneQueue.front().dis + 1 << std::endl;

    return 0;
}