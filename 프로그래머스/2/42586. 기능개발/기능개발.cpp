#include <string>
#include <vector>
#include <cmath>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    
    int curDay = 0; // 현재 배포 기준 날짜
    int cnt = 0; // 함께 배포되는 기능 개수

    for (int i=0; i<progresses.size(); i++) {

        // 각 기능이 완료되는 데 걸리는 날짜
        int day=ceil((double)(100-progresses[i])/speeds[i]);

        if(day>curDay) {
            // 지금까지 묶여있던 기능들 배포
            if(cnt>0) answer.push_back(cnt);
            // 새로운 배포 시작
            curDay = day;
            cnt = 1;
        }
        else {
            cnt++;
        }
    }
    answer.push_back(cnt);
    
    return answer;
}