#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// 전선 하나 끊고 -> 나머지 전선 계산해서 -> 최소값

vector<int> adj[101];

int dfs(int cur, int parent, int a, int b) {
    int cnt = 1;

    for (int next : adj[cur]) {
        if (next == parent) continue;
        if ((cur==a && next==b) || (cur==b && next==a)) continue;
        cnt += dfs(next, cur, a, b);
    }
    return cnt;
}

int solution(int n, vector<vector<int>> wires) {
    int answer = n;
    
    for (auto &w : wires) {
        adj[w[0]].push_back(w[1]);
        adj[w[1]].push_back(w[0]);
    }

    for (auto &w : wires) {
        int cnt = dfs(w[0], 0, w[0], w[1]);
        answer = min(answer, abs(cnt - (n - cnt)));
    }
    
    return answer;
}