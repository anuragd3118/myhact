#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adjList;
vector<int> parent;

int bfs(int size) {
    queue<int> Q;
    vector<bool> visited(size, 0);
    Q.push(size - 1);
    visited[size - 1] = 1;
    int lev = 0;
    while (!Q.empty()) {
        int l = Q.size();
        ++lev;
        while (l--) {
            int par = Q.front();
            Q.pop();
            for (auto i : adjList[par]) {
                if (visited[i]) continue;
                Q.push(i);
                parent[i] = par;
                visited[i] = 1;
                if (i == 0)
                    return lev;
            }
        }
    }
    return 0;
}

int main() {
    int n, m;
    cin >> n >> m;
    adjList.resize(n);
    parent = vector<int>(n, -1);
    for (int i = 0, a, b; i < m; ++i) {
        cin >> a >> b;
        adjList[a - 1].push_back(b - 1);
        adjList[b - 1].push_back(a - 1);
    }
    int count = bfs(n);

    if (!count) {
        cout << "IMPOSSIBLE";
    } else {
        cout << count + 1 << endl;
        int temp = 0;
        while (temp != -1) {
            cout << temp + 1 << " ";
            temp = parent[temp];
        }
        cout << endl;
    }
    return 0;
}
