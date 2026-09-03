#include <string>
#include <vector>
#include <stack>

using namespace std;

// 인덱스 + 스택 활용
vector<int> solution(vector<int> numbers) {
    vector<int> answer;
    
    for(int i=0; i<numbers.size(); i++) {
        answer.push_back(-1);
    }
    
    stack<int> s;
    
    for(int i=0; i<numbers.size(); i++) {
        while(!s.empty() && numbers[i] > numbers[s.top()]) {
            answer[s.top()] = numbers[i];
            s.pop();
        }
        s.push(i);
    }
    
    return answer;
}