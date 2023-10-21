#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Function to find the maximum element in a subsequence from index i to j
int findMaxSegment(const vector<int>& arr, int i, int j) {
    int maxElement = arr[i - 1];
    for (int k = i; k < j; ++k) {
        maxElement = max(maxElement, arr[k]);
    }
    return maxElement;
}

int main() {
    int n;
    cin >> n;
    vector<int> sequence(n);

    for (int i = 0; i < n; ++i) {
        cin >> sequence[i];
    }

    char query[20];
    while (true) {
        cin >> query;
        if (query[0] == '*') {
            break;
        }

        if (query[0] == 'f' && query[5] == 'm') { // find-max
            cout << *max_element(sequence.begin(), sequence.end()) << endl;
        } else if (query[0] == 'f' && query[5] == 'n') { // find-min
            cout << *min_element(sequence.begin(), sequence.end()) << endl;
        } else if (query[0] == 's') { // sum
            int sum = 0;
            for (int i = 0; i < n; ++i) {
                sum += sequence[i];
            }
            cout << sum << endl;
        } else if (query[0] == 'f' && query[5] == 's') { // find-max-segment
            int i, j;
            cin >> i >> j;
            cout << findMaxSegment(sequence, i, j) << endl;
        }
    }

    return 0;
}

