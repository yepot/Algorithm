#include <string>
#include <vector>
#include <algorithm>

using namespace std;

//1. 테이블 정의 D: i층 j번째 까지의 최대값
//2. 점화식 D[i][j] = max(D[i-1][j], D[i-1][j-1])+tri[i][j]
//3. 초기값 
int solution(vector<vector<int>> triangle) {
  
    int answer = 0;
    triangle[1][0] = triangle[0][0]+triangle[1][0];
    triangle[1][1] = triangle[0][0]+triangle[1][1];
    
    for(int i=2; i<triangle.size(); i++) {
        triangle[i][0] = triangle[i-1][0] + triangle[i][0];
        triangle[i][i] = triangle[i-1][i-1] + triangle[i][i];
        for(int j=1; j<i; j++) {
            triangle[i][j] = max(triangle[i-1][j], triangle[i-1][j-1]) + triangle[i][j];
        }
    }
    
    return *max_element(triangle[triangle.size()-1].begin(), triangle[triangle.size()-1].end());
}