#include <iostream>
#include <vector>
#include <limits>

using namespace std;

const int INF = numeric_limits<int>::max();

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> graph(n, vector<int>(n, INF));

    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u - 1][v - 1] = w;
    }

    // Initialize the diagonal with 0 and other entries with INF.
    for (int i = 0; i < n; i++) {
        graph[i][i] = 0;
    }

    // Floyd-Warshall algorithm to compute shortest paths.
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (graph[i][k] != INF && graph[k][j] != INF) {
                    graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
                }
            }
        }
    }

    // Print the shortest paths matrix.
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (graph[i][j] == INF) {
                cout << "-1 ";
            } else {
                cout << graph[i][j] << " ";
            }
        }
        cout << endl;
    }

    return 0;
}

