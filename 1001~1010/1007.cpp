#include <iostream>
#include <vector>

using namespace std;

long long solve(int, int);

int main() {
    int timeLimit, totalTime;
    cin >> timeLimit >> totalTime;

    cout << solve(timeLimit, totalTime);
}


long long solve(int limit, int total) {
    vector<long long> solution(total + 1, 0);
    solution[0] = 1;

    for (int i = 0; i < limit; ++i) solution[i + 1] = solution[i] << 1;

    for (int i = limit + 1; i <= total; ++i) {
        for (int j = 0; j <= limit + 1; ++j) {
            solution[i] += solution[i - j];
        }
    }

    return solution[total];
}
