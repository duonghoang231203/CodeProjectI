#include <iostream>
#include <queue>
#include <unordered_set>
using namespace std;

int waterJugProblem(int a, int b, int c) {
    queue<pair<int, int>> q;
    unordered_set<int> visited;
    q.push({0, 0});
    visited.insert(0);
    int steps = 0;
    bool found = false;

    while (!q.empty()) {
        int size = q.size();
        while (size--) {
            int jug1 = q.front().first;
            int jug2 = q.front().second;
            q.pop();

            if (jug1 == c || jug2 == c) {
                found = true;
                break;
            }

            // Pour water from jug1 to jug2
            if (jug1 > 0 && jug2 < b) {
                int amount = min(jug1, b - jug2);
                int new_state = jug1 - amount + (1001 * (jug2 + amount));
                if (visited.find(new_state) == visited.end()) {
                    q.push({jug1 - amount, jug2 + amount});
                    visited.insert(new_state);
                }
            }

            // Pour water from jug2 to jug1
            if (jug2 > 0 && jug1 < a) {
                int amount = min(jug2, a - jug1);
                int new_state = (jug1 + amount) + (1001 * (jug2 - amount));
                if (visited.find(new_state) == visited.end()) {
                    q.push({jug1 + amount, jug2 - amount});
                    visited.insert(new_state);
                }
            }

            // Fill jug1
            if (jug1 < a) {
                int new_state = a + (1001 * jug2);
                if (visited.find(new_state) == visited.end()) {
                    q.push({a, jug2});
                    visited.insert(new_state);
                }
            }

            // Fill jug2
            if (jug2 < b) {
                int new_state = jug1 + (1001 * b);
                if (visited.find(new_state) == visited.end()) {
                    q.push({jug1, b});
                    visited.insert(new_state);
                }
            }

            // Empty jug1
            if (jug1 > 0) {
                int new_state = (1001 * jug2);
                if (visited.find(new_state) == visited.end()) {
                    q.push({0, jug2});
                    visited.insert(new_state);
                }
            }

            // Empty jug2
            if (jug2 > 0) {
                int new_state = jug1;
                if (visited.find(new_state) == visited.end()) {
                    q.push({jug1, 0});
                    visited.insert(new_state);
                }
            }
        }

        if (found) {
            return steps;
        }

        steps++;
    }

    return -1;
}

int main() {
    int a, b, c;
    cin >> a >> b >> c;

    int result = waterJugProblem(a, b, c);

    cout << result << endl;

    return 0;
}
