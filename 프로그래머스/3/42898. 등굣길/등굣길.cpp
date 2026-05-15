#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// 배열 정의: D[i][j]: (i,j) 까지 갔을 때 최단경로의 개수
// 점화식 정의: D[i][j] = D[i-1][j] + D[i][j-1]
// 초기값
int solution(int m, int n, vector<vector<int>> puddles) {
    int D[101][101] = {0};
    const int MOD = 1000000007;

    for(int i = 0; i < puddles.size(); i++) {
        D[puddles[i][1] - 1][puddles[i][0] - 1] = -1;
    }

    D[0][0] = 1;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(D[i][j] == -1) {
                D[i][j] = 0;
                continue;
            }

            if(i==0 && j==0) continue;

            int up = 0;
            int left = 0;

            if(i>0) up = D[i-1][j];
            if(j>0) left = D[i][j-1];

            D[i][j] = (up + left) % MOD;
        }
    }

    return D[n-1][m-1];
}