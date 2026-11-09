#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    
    priority_queue<int, vector<int>, greater<int>> pq;
    for(int i=0; i<scoville.size(); i++) {
        pq.push(scoville[i]);
    }
    
    while(pq.top() < K) {
        if(answer > scoville.size() || pq.size() < 2) {
            answer = -1;
            break;
        }
        int tmp = pq.top();
        pq.pop();
        pq.push(tmp + pq.top() * 2);
        pq.pop();
        answer ++;
        
    }
    
    return answer;
}