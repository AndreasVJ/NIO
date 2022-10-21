#include <iostream>


int main() {

    int N;
    std::cin >> N;

    int Si, Ni, Wi, Ei;

    int citiesInNorvestige = 0;

    for (int i = 0; i < N; i++) {
        std::cin >> Si >> Ni >> Wi >> Ei;

        // Check whether the north-west corner is above the line
        if (Ni > Wi) {
            // Check whether the south-east corner is above the line
            if (Si >= Ei) {
                citiesInNorvestige++;
            }
            else {
                std::cout << "UMULIG";
                return 0;
            }
        }
    }

    std::cout << citiesInNorvestige;

    return 0;
}