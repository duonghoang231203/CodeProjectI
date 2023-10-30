#include <iostream>
#include <vector>
#include <set>
#include <algorithm>  // Include the algorithm header for sort
using namespace std;

const int MAX_NODES = 100000;

vector<int> adj[MAX_NODES + 1];
set<int> visited;

void dfs(int node) {
    visited.insert(node);
    cout << node << " ";
    
    for (int neighbor : adj[node]) {
        if (visited.find(neighbor) == visited.end()) {
            dfs(neighbor);
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for (int i = 1; i <= n; ++i) {
        sort(adj[i].begin(), adj[i].end());
    }

    for (int i = 1; i <= n; ++i) {
        if (visited.find(i) == visited.end()) {
            dfs(i);
        }
    }

    cout << endl;
    return 0;
}

