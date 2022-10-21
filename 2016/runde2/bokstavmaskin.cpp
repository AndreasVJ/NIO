#include <iostream>
#include <deque>

using namespace std;

int main() {

    int N = 0;
    cin >> N;

    string s;
    cin >> s;

    bool flipped = false;

    deque<char> output;
    output.push_back('A');

    for (int i = 0; i < N; i++) {
        if (s[i] == 'z') {
            flipped = !flipped;
        }

        else {
            if (flipped) {
                if (s[i] == 'x') {
                    output.push_back('A');
                }
                else if (s[i] == 'y') {
                    output.push_front('B');
                }
            }
            else {
                if (s[i] == 'x') {
                    output.push_front('A');
                }
                else if (s[i] == 'y') {
                    output.push_back('B');
                }
            }
        }
    }

    if (flipped) {
        for(int i = output.size()-1; i > -1; i--) {
            cout << output.at(i);
        }
    }
    else {
        for(int i = 0; i < output.size(); i++) {
            cout << output.at(i);
        }
    }

    return 0;
}