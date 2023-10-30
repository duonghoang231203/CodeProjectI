#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Edge {
    int u, v, weight;
    bool operator<(const Edge& other) const {
        return weight < other.weight;
    }
};

int find(int v, vector<int>& parent) {
    if (v == parent[v]) {
        return v;
    }
    return parent[v] = find(parent[v], parent);
}

void unite(int a, int b, vector<int>& parent, vector<int>& rank) {
    a = find(a, parent);
    b = find(b, parent);
    if (a != b) {
        if (rank[a] < rank[b]) {
            swap(a, b);
        }
        parent[b] = a;
        if (rank[a] == rank[b]) {
            rank[a]++;
        }
    }
}

int main() {
    int N, M;
    cin >> N >> M;
    
    vector<Edge> edges;
    for (int i = 0; i < M; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back({u, v, w});
    }
    
    sort(edges.begin(), edges.end());
    
    vector<int> parent(N + 1);
    vector<int> rank(N + 1, 0);
    for (int i = 1; i <= N; i++) {
        parent[i] = i;
    }
    
    int mstWeight = 0;
    for (const Edge& edge : edges) {
        int u = edge.u;
        int v = edge.v;
        int weight = edge.weight;
        
        if (find(u, parent) != find(v, parent)) {
            mstWeight += weight;
            unite(u, v, parent, rank);
        }
    }
    
    cout << mstWeight << endl;
    
    return 0;
}

