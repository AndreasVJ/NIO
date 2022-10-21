#include <iostream>
#include <string>

int main() {

    std::string key, message;
    int length;
    std::cin >> key >> length >> message;

    std::string decrypted = "";

    for (int i = 0; i < length; i++) {
        decrypted += key[(key.find(message[i]) + 25) % 26];
    }

    std::cout << decrypted;

    return 0;
};