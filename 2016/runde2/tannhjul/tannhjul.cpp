#include <iostream>
#include <vector>

using namespace std;

int main() {

    int n;
    cin >> n;

    int a;

    vector<int> result;

    for (int i = 0; i < n; i++) {
        cin >> a;
        if (a%2 == 0) {
            result.push_back(1);
        }
        else {
            result.push_back(0);
        }
    }

    for (int i = 0; i < n; i++) {
        if (result[i] == 1) {
            cout << "RIKTIG" << endl;
        }
        else {
            cout << "GALT" << endl;
        }
    }

    return 0;
}