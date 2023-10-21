#include <iostream>
#include <vector>

using namespace std;

void generateCollections(int n, int M, vector<int>& current) {
    if (n == 0) {
        if (M == 0) {
            for (int i = 0; i < current.size(); ++i) {
                cout << current[i];
                if (i < current.size() - 1) {
                    cout << " ";
                }
            }
            cout << endl << endl;
        }
        return;
    }

    for (int i = 1; i <= M; ++i) {
        if (M >= i) {
            current.push_back(i);
            generateCollections(n - 1, M - i, current);
            current.pop_back();
        }
    }
}

int main() {
    int n, M;
    cin >> n >> M;

    vector<int> current;
    generateCollections(n, M, current);

    return 0;
}
