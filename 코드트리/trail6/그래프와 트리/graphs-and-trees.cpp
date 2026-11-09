#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// 사이클 여부는 노드 개수, 간선 개수로 판단하자!
int main() {
    // Please write your code here.
    int n, m;
    cin >> n >> m;
    
    vector<int> adj[505];
    int a, b;
    for(int i=0; i<m; i++) {
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    queue<int> q;
    bool vis[505] = {0, };
    int answer = 0;

    for(int i=1; i<=n; i++) {
        int edge = 0;
        int node = 0;

        if(vis[i] == 1) continue;
        q.push(i);
        vis[i] = 1;

        while(!q.empty()) {
            int cur = q.front();
            q.pop();
            node ++;
            edge += adj[cur].size();
            for(int next : adj[cur]) {
                if(vis[next] == 1) continue;
                q.push(next);
                vis[next] = 1;
            }
        }

        // * 트리의 조건: edge/2 = node-1
        // * 양방향이니까 나누기 2 해야돼!!
        if(node-1 == edge/2) answer ++;
    }
    cout << answer;
    return 0;
}