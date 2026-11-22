#include <iostream>
#include <vector>
#include <queue>

using namespace std;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<int> adj[32001];
    int deg[32001] = {0, };

    int a, b;
    for(int i=0; i<m; i++) {
        cin >> a >> b;
        adj[a].push_back(b);
        deg[b] ++;
    }

    queue<int> q;
    for(int i=1; i<=n; i++) {
        if(deg[i] == 0) q.push(i);
    }

    while(!q.empty()) {
        int cur = q.front();
        q.pop();
        cout << cur << ' ';

        for(int next : adj[cur]) {
            deg[next] --;
            if(deg[next] == 0) q.push(next);
        }
    }

    return 0;
}