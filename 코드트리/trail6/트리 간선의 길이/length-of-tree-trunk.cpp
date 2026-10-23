#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N;
vector<pair<int, int>> adj[10001];

int bfs(int start) {
    queue<int> q;
    bool vis[10001] = {0, };
    int d[10001] = {0, };
    int farNode = 0;
    int maxDist = 0;

    q.push(start);
    vis[start] = 1;

    while(!q.empty()) {
        int cur = q.front();
        q.pop();
        for(auto [next, dist] : adj[cur]) {
            if(vis[next] == 1) continue;
            q.push(next);
            vis[next] = 1;
            d[next] = d[cur] + dist;
            if(d[next] > maxDist) {
                maxDist = d[next];
                farNode = next;
            }
        }
    }

    return farNode;
}

int main() {
    // Please write your code here.
    cin >> N;
    int a, b, w;
    int answer = 0;
    for(int i=0; i<N-1; i++) {
        cin >> a >> b >> w;
        adj[a].push_back({b, w});
        adj[b].push_back({a, w});
    }

    int start = bfs(1);
    int end = bfs(start);

    queue<int> q;
    bool vis[10001] = {0, };
    int d[10001] = {0, };

    q.push(start);
    vis[start] = 1;

    while(!q.empty()) {
        int cur = q.front();
        q.pop();
        for(auto [next, dist] : adj[cur]) {
            if(vis[next] == 1) continue;
            q.push(next);
            vis[next] = 1;
            d[next] = d[cur] + dist;
            if(next == end) answer = d[next];
        }
    }

    cout << answer;
    return 0;
}