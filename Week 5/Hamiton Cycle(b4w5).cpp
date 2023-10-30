#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool isHamiltonianGraph(vector<vector<int>>& graph, vector<bool>& visited, int currentNode, int numVisited, int startNode) {
    visited[currentNode] = true;
    numVisited++;
    
    if (numVisited == graph.size()) {
        visited[currentNode] = false;
        return graph[currentNode][startNode] == 1; // Check if there is an edge from the last node to the start node
    }
    
    for (int i = 0; i < graph.size(); i++) {
        if (graph[currentNode][i] == 1 && !visited[i]) {
            if (isHamiltonianGraph(graph, visited, i, numVisited, startNode))
                return true;
        }
    }
    
    visited[currentNode] = false;
    return false;
}

int main() {
    int T;
    cin >> T;
    
    while (T--) {
        int n, m;
        cin >> n >> m;
        
        vector<vector<int>> graph(n, vector<int>(n, 0));
        vector<bool> visited(n, false);
        
        for (int i = 0; i < m; i++) {
            int u, v;
            cin >> u >> v;
            graph[u-1][v-1] = 1;
            graph[v-1][u-1] = 1;
        }
        
        bool isHamiltonian = false;
        for (int i = 0; i < n; i++) {
            if (isHamiltonianGraph(graph, visited, i, 0, i)) {
                isHamiltonian = true;
                break;
            }
        }
        
        if (isHamiltonian)
            cout << 1 << endl;
        else
            cout << 0 << endl;
    }
    
    return 0;
}

