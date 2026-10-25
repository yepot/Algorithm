#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

vector<int> solution(vector<string> gems) {

    unordered_set<string> s(gems.begin(), gems.end());
    int cnt = s.size();
    
    int left = 0;
    int right = 0;
    
    int min_len = gems.size() + 1;
    vector<int> answer = {1, (int)gems.size()};
    unordered_map<string, int> m;
    
    while(right < gems.size()) {
        m[gems[right]] ++;

        while(m.size() == cnt) {
            
            if(right-left < min_len) {
                min_len = right - left;
                answer = {left + 1, right + 1};
            }
            
            m[gems[left]] --;
            if(m[gems[left]] == 0) {
                m.erase(gems[left]);
            }
            left++;
        }
        
        right++;
    }
    
    return answer;
}