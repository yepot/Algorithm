#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    
    int size = scoville.size();
    priority_queue<int, vector<int>, greater<int>> pq;
    
    for(auto i : scoville) {
        pq.push(i);
    }
    
    while(pq.top() < K) {
        
        if(answer >= size) return -1;
        if(pq.size() < 2) return -1;
        
        answer++;
        
        int a = pq.top();
        pq.pop();
        int b = pq.top();
        pq.pop();
        
        pq.push(a+b*2);
    }
    
    return answer;
}