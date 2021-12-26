#include <iostream>
#include <vector>

using namespace std;

int KMP(string);

int main() {
    string a, b;
    cin >> a >> b;

    cout << KMP(a + "#" + b);
}


int KMP(string input) {
    vector<int> pi(input.size(), 0);

    for (int i = 1; i < input.size(); ++i) {
        int j = i - 1;
        while (j >= 0) {
            if (input[i] == input[pi[j]]) {
                pi[i] = pi[j] + 1;
                break;
            }

            j = pi[j] - 1;
        }
    }

    return *pi.rbegin();
}