#include <string>
#include <vector>
#include <queue>

using namespace std;

// 그리디..?
long long solution(int n, vector<int> works) {
    long long answer = 0;
    
    priority_queue<int> pq;
    
    for(int i=0; i<works.size(); i++) {
        pq.push(works[i]);
    }
    
    while(n > 0) {
        int tmp = pq.top();
        pq.pop();
        pq.push(tmp-1);
        n--;
    }
    
    while(pq.size() > 0) {
        if(pq.top() < 0) {
            pq.pop();
            continue;
        }
        answer += pq.top()*pq.top();
        pq.pop();
    }
    
    return answer;
}