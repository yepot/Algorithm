#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> queue1, vector<int> queue2) {
    int answer = 0;
    
    queue<int> q1;
    queue<int> q2;
    
    // 원소*원소길이 고려해서 long long 으로 해야지!!
    long long sum1 = 0;
    long long sum2 = 0;
    
    for(int i=0; i<queue1.size(); i++) {
        q1.push(queue1[i]);
        sum1 += queue1[i];
    }
    for(int i=0; i<queue2.size(); i++) {
        q2.push(queue2[i]);
        sum2 += queue2[i];
    }
    
    if((sum1 + sum2) % 2 != 0) return -1;
    long long total = (sum1 + sum2) / 2;
    
    
    
    while(sum1 != total) {
        if(sum1 < total) {
            int tmp = q2.front();
            q1.push(tmp);
            q2.pop();
            
            sum1 += tmp;
            sum2 -= tmp;
        }
        else {
            int tmp = q1.front();
            q2.push(tmp);
            q1.pop();
            
            sum2 += tmp;
            sum1 -= tmp;
        }
        answer ++;
        if(q1.empty() || q2.empty()) return -1;
        if(answer > 600000) return -1;
    }
    
    
    return answer;
}