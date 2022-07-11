#include <iostream>
#include <string>
#include <vector>


int main() {

    int numberOfColumns, numberOfRows, numberOfInstructions;

    std::cin >> numberOfColumns >> numberOfRows >> numberOfInstructions;

    std::vector<std::string> embroidery;
    std::string firstEmbroideryLine = "";
    for (int i = 0; i < numberOfColumns; i++) {
        firstEmbroideryLine += "0";
    }
    embroidery.push_back(firstEmbroideryLine);

    int x = 0;
    int y = 0;

    for (int i = 0; i < numberOfInstructions; i++) {

        int n;
        char character;

        std::cin >> n >> character;

        for (int j = 0; j < n; j++) {
            if (y%2) {
                embroidery[y][numberOfColumns - x - 1] = character;
            }
            else {
                embroidery[y][x] = character;
            }

            x++;
            if (x == numberOfColumns && y != numberOfRows-1) {
                x = 0;
                y++;
                std::string embroideryLine = "";
                for (int k = 0; k < numberOfColumns; k++) {
                    embroideryLine += "0";
                }
                embroidery.push_back(embroideryLine);
            }
        }
    }

    for (int i = 0; i < numberOfRows; i++) {
        std::cout << embroidery[i] << std::endl;
    }

    return 0;
}