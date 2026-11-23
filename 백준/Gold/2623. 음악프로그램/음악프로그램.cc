#include <iostream>
#include <vector>
#include <queue>

using namespace std;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<int> adj[1001];
    int deg[1001] = {0, };

    for(int i=0; i<m; i++) {
        int cnt;
        int tmp[101] = {0, };

        cin >> cnt;

        for(int j=0; j<cnt; j++) {
            cin >> tmp[j];
        }

        for(int j=1; j<cnt; j++) {
            adj[tmp[j-1]].push_back(tmp[j]);
            deg[tmp[j]] ++;
        }
    }

    queue<int> q;
    for(int i=1; i<=n; i++) {
        if(deg[i] == 0) q.push(i);
    }

    vector<int> result;

    while(!q.empty()) {
        int cur = q.front();
        q.pop();
        result.push_back(cur);
                
        for(int next : adj[cur]) {
            deg[next] --;
            if(deg[next] == 0) q.push(next);
        }
    }

    // 순서 정하는 게 가능한지 여부는 사이즈로 판단!!
    if(result.size() != n) cout << 0;
    else {
        for(int i=0; i<result.size(); i++) {
            cout << result[i] << '\n';
        }
    }


    return 0;
}