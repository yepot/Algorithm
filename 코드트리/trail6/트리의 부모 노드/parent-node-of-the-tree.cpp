#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int N;
vector<int> adj[100001];
int p[100001] = {0, };

void dfs() {
    stack<int> s;
    s.push(1);
    p[1] = 1;
    while(!s.empty()) {
        int cur = s.top();
        s.pop();
        for(auto next : adj[cur]) {
            if(p[next] != 0) continue;
            s.push(next);
            p[next] = cur;
        }
    }
}

int main() {
    // Please write your code here.
    cin >> N;

    for(int i=0; i<N-1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs();

    for(int i=2; i<=N; i++) {
        cout << p[i] << '\n';
    }

    return 0;
}