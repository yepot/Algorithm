#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(vector<string> want, vector<int> number, vector<string> discount) {
    int answer = 0; // 모두 할인 받을 수 있는 회원등록 날짜의 총 일수
    
    unordered_map<string, int> origin;
    
    for(int i=0; i<want.size(); i++) {
        origin[want[i]] = number[i];
    }
    
    for(int i=0; i<=discount.size()-10; i++) {
        unordered_map<string, int> m = origin;
        
        for(int j=i; j<i+10; j++) {
            if(m.find(discount[j]) == m.end()) continue;
            m[discount[j]]--;
        }
        
        bool check = 1;
        for(auto s : m) {
            if(s.second > 0) {
                check = 0;
                break;
            }
        }
        
        if(check) answer++;
    }
    
    return answer;
}