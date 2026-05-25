#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// 특정 시간에 몇 명을 끝낼 수 있는지를 보자
// Parameter Search
long long solution(int n, vector<int> times) {
    
    sort(times.begin(), times.end());
    long long left = 1;
    long long right = (long long)times.back()*n;
    
    while(left < right) {
        long long cnt = 0;
        long long mid = (left+right)/2;
        
        for(int i : times) {
            cnt += mid/i;
        }
        
        if(cnt>=n) right = mid;
        else left = mid+1;
    }
    
    return left;
}