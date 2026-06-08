#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;

int n, k, m;
int board[101][101];
bool vis[101][101];

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

vector<pair<int, int>> stones;
vector<pair<int, int>> selected;
vector<pair<int, int>> starts;

int answer = 0;

int bfs() {
    memset(vis, false, sizeof(vis));

    queue<pair<int, int>> q;
    int cnt = 0;

    for (auto [x, y] : starts) {
        if (!vis[x][y]) {
            vis[x][y] = true;
            q.push({x, y});
            cnt++;
        }
    }

    while (!q.empty()) {
        auto cur = q.front();
        q.pop();

        for (int dir = 0; dir < 4; dir++) {
            int nx = cur.first + dx[dir];
            int ny = cur.second + dy[dir];

            if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
            if (vis[nx][ny]) continue;
            if (board[nx][ny] == 1) continue;

            vis[nx][ny] = true;
            q.push({nx, ny});
            cnt++;
        }
    }

    return cnt;
}

void backtracking(int idx, int cnt) {
    if (cnt == m) {
        // 선택한 돌 제거
        for (auto [x, y] : selected) {
            board[x][y] = 0;
        }

        answer = max(answer, bfs());

        // 원상복구
        for (auto [x, y] : selected) {
            board[x][y] = 1;
        }

        return;
    }

    if (idx == stones.size()) return;

    // 현재 돌 선택
    selected.push_back(stones[idx]);
    backtracking(idx + 1, cnt + 1);
    selected.pop_back();

    // 현재 돌 선택 안 함
    backtracking(idx + 1, cnt);
}

int main() {
    cin >> n >> k >> m;

    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            cin >> board[i][j];

            if (board[i][j] == 1) {
                stones.push_back({i, j});
            }
        }
    }

    for (int i = 0; i < k; i++) {
        int r, c;
        cin >> r >> c;
        starts.push_back({r-1, c-1});
    }

    backtracking(0, 0);

    cout << answer;

    return 0;
}