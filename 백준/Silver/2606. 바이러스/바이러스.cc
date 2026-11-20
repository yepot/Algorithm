#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> adj[105];
bool vis[105] = {0, };

int bfs(int start) {
    int cnt = 0;
    queue<int> q;
    q.push(start);
    vis[start] = 1;

    while(!q.empty()) {
        int cur = q.front();
        q.pop();
        for(auto next : adj[cur]) {
            if(vis[next] == 1) continue;
            q.push(next);
            vis[next] = 1;
            cnt ++;
        }
    }

    return cnt;

}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int num, n;
    cin >> num >> n;

    int a, b;
    for(int i=0; i<n; i++) {
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    cout << bfs(1);
    return 0;
}