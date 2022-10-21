#include <iostream>

int main() {

    int A1, A2, A3, B1, B2, B3;
    std::cin >> A1 >> A2 >> A3 >> B1 >> B2 >> B3;

    int Anne = A1 + A2 + A3;
    int Berit = B1 + B2 + B3;

    if (Berit > Anne) {
        std::cout << "Berit" << "\n";
    }
    else if (Berit < Anne) {
        std::cout << "Anne" << "\n";
    }
    else {
        std::cout << "Uavgjort" << "\n";
    }

    return 0;
}