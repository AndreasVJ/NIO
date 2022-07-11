#include <iostream>
#include <vector>

using namespace std;

//----------------------------------------------------------------
// Not done

int main() {

    int N, K, Xg;
    cin >> N >> K >> Xg;

    vector<int> addresses;

    for (int i = 0; i < N; i++) {

        int address;
        cin >> address;

        addresses.push_back(address - Xg);
    }

    for (int i = 0; i < N; i++) {
        cout << addresses[i] << endl;
    }

    return 0;
}