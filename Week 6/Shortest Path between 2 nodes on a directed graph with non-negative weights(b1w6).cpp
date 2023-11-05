#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

const int INF = numeric_limits<int>::max();

struct Edge {
    int to;
    int weight;
};

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<Edge>> graph(n);
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u - 1].push_back({v - 1, w});
    }

    int s, t;
    cin >> s >> t;
    s--;
    t--;

    vector<int> distance(n, INF);
    distance[s] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, s});

    while (!pq.empty()) {
        int u = pq.top().second;
        int dist = pq.top().first;
        pq.pop();

        if (dist > distance[u]) {
            continue;
        }

        for (const Edge& edge : graph[u]) {
            int v = edge.to;
            int w = edge.weight;
            if (distance[u] + w < distance[v]) {
                distance[v] = distance[u] + w;
                pq.push({distance[v], v});
            }
        }
    }

    if (distance[t] == INF) {
        cout << -1 << endl;
    } else {
        cout << distance[t] << endl;
    }

    return 0;
}

