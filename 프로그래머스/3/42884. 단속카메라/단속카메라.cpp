#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// 겹치는 부분이 생기는지
int solution(vector<vector<int>> routes) {
    int answer = 1;
    
    sort(routes.begin(), routes.end());
    
    int start = routes[0][0];
    int end = routes[0][1];
    
    for(int i=1; i<routes.size(); i++) {
        if(routes[i][0] > end) {
            answer++;
            start = routes[i][0];
            end = routes[i][1];
        }
        if(routes[i][0] > start && routes[i][0] < end) {
            start = routes[i][0];
        }
        if(routes[i][1] > start && routes[i][1] < end) {
            end = routes[i][1];
        }
        
    }
    
    return answer;
}