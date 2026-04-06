#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    vector<int> res[1001];
    bool vis[1001];

    //그래프 입력
    for(int i=0; i<m; i++) {
        int u, v;
        cin >> u >> v;
        res[u].push_back(v);
        res[v].push_back(u);
    }

    //BFS
    int cnt = 0;
    for(int i=1; i<=n; i++) {
        if(vis[i]) continue;
        cnt++;
        queue<int> q;
        q.push(i);
        vis[i] = true;
        while(!q.empty()) {
            int cur = q.front();
            q.pop();
            for(auto nxt: res[cur]) {
                if(vis[nxt]) continue;
                q.push(nxt);
                vis[nxt] = true;
            }
        }
    }
    cout << cnt;
}