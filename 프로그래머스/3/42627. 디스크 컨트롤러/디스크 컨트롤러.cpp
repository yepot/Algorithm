#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

// 1. 소요시간 짧은 것 -> 2. 요청 시각이 빠른 것 -> 3. 작업 번호가 작은 것
// 대기 큐 있음
// [요청시점, 소요시간]
int solution(vector<vector<int>> jobs) {
    int answer = 0;
    
    sort(jobs.begin(), jobs.end());
    int time = 0;
    // 소요시간, 요청시점
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    int idx = 0;
    
    while (idx<jobs.size() || !pq.empty()) {
        
        while(idx<jobs.size() && jobs[idx][0]<=time) {
            pq.push({jobs[idx][1], jobs[idx][0]});
            idx++;
        }

        if(!pq.empty()) {
            auto i = pq.top();
            pq.pop();
            time += i.first;
            answer += time - i.second;
        }
        
        else { 
            time = jobs[idx][0];
        }
    }
    
    return answer/jobs.size();
}