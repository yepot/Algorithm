#include <string>
#include <vector>
#include <cmath>

using namespace std;

// 그리디
int solution(int storey) {
    int answer = 0;
    
    while(storey > 0) {
        int cur = storey%10;
        int next = (storey/10)%10;
        
        if(cur > 5) {
            answer += 10-cur;
            storey += 10;
        }
        else if(cur < 5) {
            answer += cur;
        } 
        else { // 5인 경우: 다음 자릿수가 5 이상이면 올림, 아니면 버림
            if (next >= 5) {
                answer += 5;
                storey += 10;
            }
            else {
                answer += 5;
            }
        }
        
        storey /= 10;
    }
    
    return answer;
}