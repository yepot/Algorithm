#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> adj[100001];
// int dist[100001][100001] = {0, }; // 이건.. 40GB 필요 -> 너무 큰 전역 배열로 링크 오류 발생
int maxDist[100001]; // 사람들 중에서 i까지 가는 가장 먼 거리
int visNode[100001] = {0, }; // 해당 노드에 몇 명 방문 가능한지

void bfs(int start, int n) { // start -> 1, start -> 2, ..., start -> n 까지 확인
    int dist[100001]; // start에서 dist[i]까지 거리
    for(int i=0; i<100001; i++) {
        dist[i] = -1;
    }
    bool vis[100001] = {0, };
    
    queue<int> q;
    q.push(start);
    dist[start] = 0;
    vis[start] = 1;

    while(!q.empty()) {
        int cur = q.front();
        q.pop();
        for(int next : adj[cur]) {
            if(vis[next]) continue;
            q.push(next);
            vis[next] = 1;
            dist[next] = dist[cur] + 1;
        }
    }

    for(int i=1; i<=n; i++) {
        if(dist[i] == -1) continue;
        if(dist[i] > maxDist[i]) maxDist[i] = dist[i];
        visNode[i] ++;
    }
}

int main() {
    // Please write your code here.
    int n, m, k;
    cin >> n >> m >> k;

    int a, b;
    for(int i=0; i<m; i++) {
        cin >> a >> b;
        adj[a].push_back(b);
    }

    for(int i=0; i<100001; i++) {
        maxDist[i] = -1;
    }

    int p;
    for(int i=0; i<k; i++) {
        cin >> p;
        bfs(p, n);
    }

    int min_node = -1;
    int min_dist = 100001;
    for(int i=1; i<=n; i++) {
        if(visNode[i] != k) continue;
        if(maxDist[i] < min_dist) {
            min_dist = maxDist[i];
            min_node = i;
        }
    }
    
    if (min_node == -1) cout << -1;
    else cout << min_dist;
    return 0;
}