#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// parametric search
// 7 10 14 20 21 28 30 ...
// 0 ... 60 시간 시간 하나씩
long long solution(int n, vector<int> times) {
    
    sort(times.begin(), times.end());
    long long left = 1;
    long long right = (long long)times[times.size()-1] * n;
    
    while(left < right) {
        long long cnt = 0;
        long long mid = (left + right) / 2;
        
        // 몇 명 통과 가능한 지 나누기로 time으로 나누어보면 가능
        for(int i : times) {
            cnt += mid / i;
        }
        
        if(cnt >= n) right = mid;
        else left = mid + 1;
    }
    
    return left;
}