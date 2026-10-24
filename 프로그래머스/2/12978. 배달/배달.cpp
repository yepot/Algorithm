#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int solution(int N, vector<vector<int> > road, int K) {
    int answer = 0;
    
    vector<pair<int, int>> adj[55];
    int d[55] = {0, };
    for(int i=1; i<51; i++) { // d배열 아주 큰 수로 초기화
        d[i] = 10000000;
    }
    
    for(int i=0; i<road.size(); i++) {
        adj[road[i][0]].push_back({road[i][1], road[i][2]});
        adj[road[i][1]].push_back({road[i][0], road[i][2]});
    }
    
    queue<int> q;
    q.push(1);
    d[1] = 0;
    
    while(!q.empty()) {
        int cur = q.front();
        q.pop();
        for(auto [next, weight] : adj[cur]) {
            if (d[cur] + weight < d[next]) {
                d[next] = d[cur] + weight;
                q.push(next);
            }
        }
    }
    
    for(int i=1; i<=N; i++) {
        if(d[i] <= K) answer++;
    }

    return answer;
}