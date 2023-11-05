#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

const int MAXN = 10005;
const int INF = 1e9;

vector<int> graph[MAXN];
int capacity[MAXN][MAXN];
int parent[MAXN];

int bfs(int source, int sink) {
    fill(parent, parent + MAXN, -1);
    queue<pair<int, int>> q;
    q.push({source, INF});

    while (!q.empty()) {
        int cur = q.front().first;
        int flow = q.front().second;
        q.pop();

        for (int next : graph[cur]) {
            if (parent[next] == -1 && capacity[cur][next] > 0) {
                int new_flow = min(flow, capacity[cur][next]);
                parent[next] = cur;
                if (next == sink) {
                    return new_flow;
                }
                q.push({next, new_flow});
            }
        }
    }
    return 0;
}

int maxFlow(int source, int sink) {
    int flow = 0;
    int new_flow;

    while (new_flow = bfs(source, sink)) {
        flow += new_flow;
        int cur = sink;
        while (cur != source) {
            int prev = parent[cur];
            capacity[prev][cur] -= new_flow;
            capacity[cur][prev] += new_flow;
            cur = prev;
        }
    }

    return flow;
}

int main() {
    int N, M;
    cin >> N >> M;

    int source, sink;
    cin >> source >> sink;

    for (int i = 0; i < M; i++) {
        int u, v, c;
        cin >> u >> v >> c;
        graph[u].push_back(v);
        graph[v].push_back(u);
        capacity[u][v] += c;
    }

    int max_flow = maxFlow(source, sink);
    cout << max_flow << endl;

    return 0;
}

