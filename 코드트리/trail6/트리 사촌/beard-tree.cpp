#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// 1 -> 3,4,5
// 3 -> 8,9
// 4 -> 15
// 5 -> 30 31 32
int main() {
    // Please write your code here.
    int N, K, idx;
    cin >> N >> K;

    int a[1001] = {0, };
    for(int i=0; i<N; i++) {
        cin >> a[i];
        if(a[i] == K) idx = i;
    }

    vector<int> adj[1001];
    int parent[1001];
    parent[0] = -1;

    // a index 사용할거임!
    int p = 0;

    for(int i=1; i<N; i++) {
        if(i>1 && a[i] != a[i-1]+1) p++;
        adj[p].push_back(i);
        parent[i] = p;
    }

    int depth[1001] = {0, };
    bool vis[1001] = {0, };

    queue<int> q;
    q.push(0);
    vis[0];

    while(!q.empty()) {
        int cur = q.front();
        q.pop();
        for(int next : adj[cur]) {
            if(vis[next]) continue;
            q.push(next);
            vis[next] = 1;
            depth[next] = depth[cur] + 1;
        }
    }
    
    int answer = 0;
    if(depth[idx] >= 2) { // 깊이가 2 이상이어야 조부모가 있음!!!
        for(int i=0; i<N; i++) {
            if(depth[i] != depth[idx]) continue;
            if(parent[i] != parent[idx] && parent[parent[i]] == parent[parent[idx]]) answer++;
        }
    }

    cout << answer;
    return 0;
}