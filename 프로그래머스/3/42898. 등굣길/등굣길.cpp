#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// D[i][j] : (i, j) 까지 최단경로 개수
// D[i][j] = D[i-1][j] + D[i][j-1]
int solution(int m, int n, vector<vector<int>> puddles) {
    
    int D[105][105] = {0, };
    D[0][0] = 1;
    
    for(int i=0; i<puddles.size(); i++) {
        D[puddles[i][1]-1][puddles[i][0]-1] = -1;
    }
    
    for(int i=1; i<n; i++) {
        if(D[i][0] == -1) D[i][0] = 0;
        else D[i][0] = D[i-1][0];
    }

    for(int i=1; i<m; i++) {
        if(D[0][i] == -1) D[0][i] = 0;
        else D[0][i] = D[0][i-1];
    }
    
    for(int i=1; i<n; i++) {
        for(int j=1; j<m; j++) {
            if(D[i][j] == -1) {
                D[i][j] = 0;
                continue;
            }
            D[i][j] = D[i-1][j] + D[i][j-1];
            D[i][j] %= 1000000007;
        }
    }
    
    return D[n-1][m-1];
}