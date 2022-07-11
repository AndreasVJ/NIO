#include <iostream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

int main() {

    int N;
    cin >> N;

    vector<int> gueses;

    for (int i = 0; i < N; i++) {
        int guess;
        cin >> guess;
        gueses.push_back(guess);
    }

    sort(gueses.begin(), gueses.end());

    int lowest_number = gueses[0];

    for (int i = 1; i < N;) {
        if (i >= N) {
            lowest_number = -1;
            break;
        }
        if (gueses[i] == lowest_number) {

            i++;
            if (i >= N) {
                lowest_number = -1;
                break;
            }
            while (gueses[i] == lowest_number) {
                i++;
            }
            if (i >= N) {
                lowest_number = -1;
                break;
            }
            lowest_number = gueses[i];
            i++;
        }
        else {
            break;
        }
    }

    cout << lowest_number << endl;

    return 0;
}