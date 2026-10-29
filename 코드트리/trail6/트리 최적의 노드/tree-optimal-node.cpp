#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> adj[100001];

vector<int> dist(int k) {

    int d[100001] = {0, };
    bool vis[100001] = {0, };
    int idx = k;
    int max_dist = 0;

    queue<int> q;
    q.push(k);
    vis[k] = 1;

    while(!q.empty()) {
        int cur = q.front();
        q.pop();
        for(int next : adj[cur]) {
            if(vis[next]) continue;
            q.push(next);
            vis[next] = 1;
            d[next] = d[cur] + 1;
            if(d[next] > max_dist) {
                max_dist = d[next];
                idx = next;
            }

        }
    }
    return {idx, max_dist};
}

// 가장 먼 노드까지의 거리가 최소가 되도록
// 지름 구해서 나누기 2 해주기!!!
int main() {
    // Please write your code here.

    int n;
    cin >> n;

    int a, b;
    for(int i=0; i<n-1; i++) {
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    vector<int> m = dist(1);
    int next = m[0];
    
    cout << (dist(next)[1]+1) / 2; // 올림하기 위해 +1 해줘야돼!!

    return 0;
}