#include <iostream>
#include <vector>
#include <stack>
using namespace std;

// 홀수면 1, 짝수면 0
int main() {
    // Please write your code here.
    int N;
    vector<int> adj[100001];
    int a, b;
    int dist[100001] = {0, };
    bool vis[100001] = {0, };
    int sum = 0;
    cin >> N;

    for(int i=0; i<N-1; i++) {
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    stack<int> s;
    s.push(1);
    vis[1] = 1;
    
    while(!s.empty()) {
        int cur = s.top();
        s.pop();

        if(cur!=1 && adj[cur].size()==1) {
            sum += dist[cur];
        }

        for(int next : adj[cur]) {
            if(vis[next] == 1) continue;
            s.push(next);
            vis[next] = 1;
            dist[next] = dist[cur] + 1;
        }
    }    

    cout << sum%2;
}