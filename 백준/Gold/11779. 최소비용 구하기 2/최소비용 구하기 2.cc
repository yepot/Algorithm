#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector<pair<int, int>> adj[1005];
int dist[1005] = {0, };
int parent[1005] = {0, };
const int INF = 1e9;

void dijkstra(int start, int end) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    
    pq.push({0, start});
    dist[start] = 0;

    while(!pq.empty()) {
        auto cur = pq.top();
        pq.pop();

        if(cur.first > dist[cur.second]) continue; // 이것도 꼭 필요
        if(cur.second == end) break; // end가 "꺼내졌을 때" 종료시켜!!!

        for(auto [next, weight] : adj[cur.second]) {
            if(dist[cur.second] + weight < dist[next]) {
                dist[next] = dist[cur.second] + weight;
                pq.push({dist[next], next});
                parent[next] = cur.second;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    for(int i=0; i<=n; i++) {
        dist[i] = INF;
    }

    int a, b, w;
    for(int i=0; i<m; i++) {
        cin >> a >> b >> w;
        adj[a].push_back({b, w});
    }

    int start, end;
    cin >> start >> end;
    dijkstra(start, end);

    vector<int> city;
    int cur = end;
    while(cur != 0) {
        city.push_back(cur);
        cur = parent[cur];
    }

    reverse(city.begin(), city.end());

    cout << dist[end] << '\n';
    cout << city.size() << '\n';
    for(int i=0; i<city.size(); i++) {
        cout << city[i] << ' ';
    }

    return 0;
}