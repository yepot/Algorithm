#include <string>
#include <vector>
#include <set>

using namespace std;

// 동일한 가짓수로 나누기
// 공평하게 자르는 방법의 수 구하기
int solution(vector<int> topping) {
    int answer = 0;
    
    set<int> front, back;
    
    vector<int> tmpF = topping;
    vector<int> tmpB = topping;
    
    for(int i=0; i<topping.size(); i++) {
        front.insert(tmpF[i]);
        tmpF[i] = front.size();
    }

    for(int i=topping.size()-1; i>=0; i--) {
        back.insert(tmpB[i]);
        tmpB[i] = back.size();
    }
    
    for(int i=1; i<topping.size(); i++) {
        if(tmpF[i-1] == tmpB[i]) answer++;
    }
    
    return answer;
}