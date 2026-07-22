#include <string>
#include <vector>

using namespace std;

// 넓이 기준으로 가로세로 하면서 테두리 빼면서 노란색 만큼 남는지 확인
bool check(int brown, int yellow, int w, int h) {
    while(brown > 0) {
        brown -= 2*(w+h-2);
        w -= 2;
        h -= 2;
    }
    if(brown == 0 && w*h == yellow) return true;
    else return false;
}

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    // 일단 더한 게 넓이랑 같아야 함
    int area = brown + yellow;
    int w = 0;
    int h = 0;
    
    for(int i=3; i<=area/2; i++) {
        if(area%i != 0) continue;
        if(check(brown, yellow, area/i, i)) {
            answer.push_back(area/i);
            answer.push_back(i);
            break;
        }
    }
    return answer;
}