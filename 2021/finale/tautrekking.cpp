#include <iostream>
#include <string>


int main() {

    int N;
    std::cin >> N;

    std::string rope;
    std::cin >> rope;

    rope.push_back(rope.back() == 'b' ? 'r' : 'b');

    int K = 0;
    int count = 0;
    int prevCount = 0;
    char prevColor = rope[0];

    for (char color : rope) {
        if (color != prevColor) {
            K = std::max(K, std::min(count, prevCount));
            prevCount = count;
            prevColor = color;
            count = 0;
        }
        count++;
    }

    std::cout << K;

    return 0;
}