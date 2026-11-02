#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

vector<pair<int, int>> adj[100001];

// 최대 노드에 excluded는 제외해야함
pair<int, int> func(int start, int excluded) {
    bool vis[100001] = {0, };
    int dist[100001] = {0, };

    int max_index = start;
    int max_dist = 0;

    queue<int> q;
    q.push(start);
    vis[start] = 1;

    while(!q.empty()) {
        int cur = q.front();
        q.pop();
        for(auto [next, weight] : adj[cur]) {
            if(vis[next]) continue;
            q.push(next);
            vis[next] = 1;
            dist[next] = dist[cur] + weight;
            if(dist[next] > max_dist && next != excluded) {
                max_dist = dist[next];
                max_index = next;
            }
        }
    }

    return {max_index, max_dist};
}

// 두 번째로 먼 두 정점간의 거리
int main() {
    // Please write your code here.
    int n;
    cin >> n;

    int a, b, w;
    for(int i=0; i<n-1; i++) {
        cin >> a >> b >> w;
        adj[a].push_back({b, w});
        adj[b].push_back({a, w});
    }

    int n1 = func(1, -1).first;
    int n2 = func(n1, -1).first;

    int answer = max(func(n1, n2).second, func(n2, n1).second);
    cout << answer;

    return 0;
}