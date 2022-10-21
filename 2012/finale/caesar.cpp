#include <iostream>


int main() {

    std::string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

    int N;
    std::cin >> N;

    std::string word;
    std::cin >> word;

    for (int i = 0; i < word.size(); i++) {
        word[i] = alphabet[(alphabet.find(word[i]) + N)%26];
    }

    std::cout << word;

    return 0;
}