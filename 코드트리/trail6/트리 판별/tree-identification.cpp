#include <iostream>
#include <vector>
#include <queue>
#include <set>

using namespace std;

int M;
vector<int> adj[10005];
int indegree[10005] = {0, }; // 들어오는 간선 수 저장해야돼!!
bool vis[10005] = {0, };
set<int> node;

void bfs(int root) {
    queue<int> q;
    q.push(root);
    vis[root] = 1;

    while(!q.empty()) {
        int cur = q.front();
        q.pop();
        for(auto next : adj[cur]) {
            if(vis[next]) continue;
            q.push(next);
            vis[next] = 1;
        }
    }
}

int main() {
    // Please write your code here.
    cin >> M;
    for(int i=0; i<M; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);

        node.insert(a);
        node.insert(b);
        indegree[b] ++;
    }

    int root = -1;
    int rootCnt = 0;
    for(auto n : node) {
        if(indegree[n] == 0) {
            root = n;
            rootCnt ++;
        }
    }

    if(rootCnt != 1) {
        cout << 0;
        return 0;
    }

    bfs(root);

    int answer = 1;
    for(auto n : node) {
        if(vis[n] == 0) answer = 0;
        if(n!=root && indegree[n]!=1) answer = 0;
    }
   
    
    cout << answer;
    return 0;
}