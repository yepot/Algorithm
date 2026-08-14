#include <string>
#include <vector>
#include <stack>

using namespace std;

int solution(vector<int> order) {
    int answer = 0;

    int num = 1; // 현재 나오고 있는 상자 번호
    int idx = 0;

    stack<int> s;

    while(idx < order.size()) {

        // 현재 메인 컨베이어 상자가 원하는 상자 일 때
        if(num<=order.size() && num==order[idx]) {
            num++;
            idx++;
            answer++;
        }

        // 보조 맨 위 상자가 원하는 상자 일 때
        else if(!s.empty() && s.top()==order[idx]) {
            s.pop();
            idx++;
            answer++;
        }

        // 아직 메인 컨베이어에 상자가 남아있을 때
        else if(num<=order.size()) {
            s.push(num);
            num++;
        }

        // 이제 더 이상 불가능
        else {
            break;
        }
    }

    return answer;
}