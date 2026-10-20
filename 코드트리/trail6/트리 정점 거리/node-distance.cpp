#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N, M;
vector<pair<int, int>> adj[1001];

int func(int a, int b) {
    if(a == b) return 0;

    int result = 0;
    queue<int> q;
    bool vis[1001] = {0, };
    int d[1001] = {0, };

    q.push(a);
    vis[a] = 1;

    while(!q.empty()) {
        int cur = q.front();
        q.pop();
        for(auto [next, dist] : adj[cur]) {
            if(vis[next] == 1) continue;
            q.push(next);
            vis[next] = 1;
            d[next] = d[cur] + dist;
            if(next == b) return d[next];
        }
    }
}

int main() {
    // Please write your code here.
    cin >> N >> M;
    int a, b, dist;
    for(int i=0; i<N-1; i++) {
        cin >> a >> b >> dist;
        adj[a].push_back({b, dist});
        adj[b].push_back({a, dist});
    }

    for(int i=0; i<M; i++) {
        cin >> a >> b;
        cout << func(a, b) << '\n';
    }


    return 0;
}