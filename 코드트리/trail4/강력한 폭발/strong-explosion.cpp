#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
int arr[30][30];
int ans = 0;
vector<pair<int, int>> bombs;

int dx[3][5] = {
    {0, -2, -1, 1, 2},
    {0, -1, 0, 1, 0},
    {0, -1, -1, 1, 1}
};

int dy[3][5] = {
    {0, 0, 0, 0, 0},
    {0, 0, -1, 0, 1},
    {0, -1, 1, -1, 1}
};

int selected[30]; // 어떤 폭탄 골랐는지

void caculate() { // 폭탄 개수
    bool vis[30][30] = {0, };
    for(int i=0; i<bombs.size(); i++) {
        auto cur = bombs[i];
        int type = selected[i];

        for(int idx=0; idx<5; idx++) {
            int nx = cur.first + dx[type][idx];
            int ny = cur.second + dy[type][idx];
            if(nx<0 || nx>=n || ny<0 || ny>=n) continue;
            vis[nx][ny] = 1;
        }
    }

    int cnt = 0;
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            if(vis[i][j] == 1) cnt++;
        }
    }

    if(cnt > ans) ans = cnt;
}

void func(int k) {
    if(k == bombs.size()) {
        caculate();
        return;
    }

    for(int type=0; type<3; type++) {
        selected[k] = type;
        func(k+1);
    }
}

int main() {
    // Please write your code here.
    cin >> n;
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cin >> arr[i][j];
            if(arr[i][j] == 1) {
                bombs.push_back({i, j});
            }
        }
    }
    func(0);
    cout << ans;

    return 0;
}