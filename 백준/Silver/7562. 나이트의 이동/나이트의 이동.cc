#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

#define X first
#define Y second
int dist[305][305];
int dx[8] = {-2, -1, -2, -1, 2, 1, 1, 2};
int dy[8] = {-1, -2, 1, 2, 1, 2, -2, -1};

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    
    // 나이트가 움직일 수 있는 칸
    // (-2,-1), (-1,-2), (-2,+1), (-1,+2), (2,1), (1,2), (1,-2), (2,-1)

    int l;
    for(int i=0; i<t; i++) {
        cin >> l;
        for(int j=0; j<l; j++) {
            fill(dist[j], dist[j]+l, -1);
        }

        queue <pair<int, int>> Q;
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        Q.push({a, b});
        dist[a][b] = 0;

        while(!Q.empty()) {
            auto cur = Q.front();
            Q.pop();
            if(cur.X==c && cur.Y==d) continue;
            for(int j=0; j<8; j++) {
                int nx = cur.X + dx[j];
                int ny = cur.Y + dy[j];
                if(nx<0 || nx>=l || ny<0 || ny >=l) continue;
                if(dist[nx][ny]>=0) continue;
                dist[nx][ny] = dist[cur.X][cur.Y] + 1;
                Q.push({nx, ny});
            }
        }
        cout << dist[c][d] << '\n';
    }

}