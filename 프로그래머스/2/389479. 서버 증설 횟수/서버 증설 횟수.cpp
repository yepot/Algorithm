#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(vector<int> players, int m, int k) {
    int answer = 0;
    unordered_map<int, int> due; // int 초에 서버 int개 반납
    
    int cur = 0; // 현재 서버 수
    for(int t=0; t<24; t++) {
        // 1. 운영 시간이 끝난 서버 반납
        cur -= due[t]; 

        // 2. 이번 시간에 필요한 증설 서버 수
        int need = players[t] / m;

        // 3. 부족한 만큼만 추가
        if(cur < need) {
            int add = need - cur;
            cur += add;
            answer += add;
            due[t + k] += add;
        }
    }
    
    return answer;
}