#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

// 간선 하나씩 지우면서 지우고 생기는 두 트리의 지름의 합+지운 간선 가중치의 합이 가장 큰 애 찾기!!!
vector<pair<int, int>> adj[2005];

pair<int, int> bfs(int start, int removeA, int removeB) {
    bool vis[2005] = {0, };
    int dist[2005] = {0, };

    int max_index = start; // start로 초기화해!!!!
    int max_dist = 0;

    queue<int> q;
    q.push(start);
    vis[start] = 1;

    while(!q.empty()) {
        int cur = q.front();
        q.pop();
        for(auto [next, weight] : adj[cur]) {
            if((cur == removeA && next == removeB) || (cur == removeB && next == removeA)) continue;
            if(vis[next]) continue;
            q.push(next);
            vis[next] = 1;
            dist[next] = dist[cur] + weight;
            if(dist[next] > max_dist) {
                max_dist = dist[next];
                max_index = next;
            }
        }
    }

    return {max_index, max_dist};

}

int main() {
    // Please write your code here.
    int n;
    cin >> n;

    int a[2005];
    int b[2005];
    int w[2005];
    for(int i=0; i<n-1; i++) {
        cin >> a[i] >> b[i] >> w[i];
        adj[a[i]].push_back({b[i], w[i]});
        adj[b[i]].push_back({a[i], w[i]});
    }
    
    int answer = -1;
    for(int i=0; i<n-1; i++) {
        int n1 = bfs(a[i], a[i], b[i]).first;
        int n2 = bfs(n1, a[i], b[i]).second;

        int m1 = bfs(b[i], a[i], b[i]).first;
        int m2 = bfs(m1, a[i], b[i]).second;

        answer = max(answer, n2 + m2 + w[i]);
    }
    
    cout << answer;
    return 0;
}