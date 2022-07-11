#include <iostream>
 
 
int main()
{
    int number, numberOfGuesses;
    std::cin >> number >> numberOfGuesses;

    int guesses[numberOfGuesses];

    for (int i = 0; i < numberOfGuesses; i++) {
        int guess;
        std::cin >> guess;
        guesses[i] = guess;
    }

    for (int i = 0; i < numberOfGuesses; i++ ){
        if (guesses[i] < number) {
            std::cout << "FOR LITE" << std::endl;
        }
        else if (guesses[i] > number) {
            std::cout << "FOR MYE" << std::endl;
        }
        else {
            std::cout << "RIKTIG" << std::endl;
        }
    }

    return 0;
}