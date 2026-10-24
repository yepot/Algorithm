#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// D[i][j]: i번째줄 j번째 숫자까지 합 최댓값
int solution(vector<vector<int>> triangle) {
    int answer = 0;
    
    int D[501][501];
    D[0][0] = triangle[0][0];
    
    for(int i=1; i<triangle.size(); i++) {
        for(int j=0; j<i+1; j++) {
            if(j == 0) D[i][j] = D[i-1][j] + triangle[i][j];
            else if(j == i) D[i][j] = D[i-1][j-1] + triangle[i][j];
            else D[i][j] = max(D[i-1][j] + triangle[i][j], D[i-1][j-1]+triangle[i][j]);
        }
    }
    
    for(int i=0; i<triangle.size(); i++) {
        for(int j=0; j<i+1; j++) {
            answer = max(answer, D[i][j]);
        }
    }
    
    return answer;
}