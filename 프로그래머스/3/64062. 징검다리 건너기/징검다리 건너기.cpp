#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// 이분탐색이라니.....
int solution(vector<int> stones, int k) {
    int answer = 0;

    int left = 1;
    int right = *max_element(stones.begin(), stones.end());
    
    while(left <= right) {
        int mid = (left+right)/2;
        bool check = 1;
        int cnt = 0;
        
        for(int i=0; i<stones.size(); i++) {
            if(stones[i] < mid) cnt++;
            else cnt = 0;
            
            if(cnt >= k) {
                check = 0;
                break;
            }
            
        }
        
        if(check) {
            answer = mid;
            left = mid+1;
        }
        else right = mid-1;
        
    }
    
    return answer;
}