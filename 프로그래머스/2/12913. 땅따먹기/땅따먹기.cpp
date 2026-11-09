#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// D[i][j] : i행 j열 까지 최고점
// D[i][3] = land[i][3] + max(D[i-1][0], D[i-1][1], D[i-1][2])
int solution(vector<vector<int> > land) {
    int answer = 0;
    int n = land.size();

    int D[100005][4] = {0, };
    for(int j=0; j<4; j++) D[0][j] = land[0][j];
    
    for(int i=1; i<n; i++) {
        for(int j=0; j<4; j++) {
            for(int k=0; k<4; k++) {
                if(j == k) continue;
                D[i][j] = max(D[i][j], land[i][j] + D[i-1][k]);
            }
            answer = max(answer, D[i][j]);
        }
    }

    return answer;
}