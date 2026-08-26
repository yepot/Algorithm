#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(string msg) {
    vector<int> answer;
    
    vector<string> v;
    for(int i=0; i<26; i++) {
        v.push_back(to_string('A'+i));
    }
    
    for(int i=0; i<msg.size(); i++) {
        string tmp = to_string(msg[i]);
        while(++i < msg.size()) {
            tmp += msg[i];
            auto it = find(v.begin(), v.end(), tmp);
            if(it == v.end()) {
                i--;
                v.push_back(tmp);
                tmp.pop_back();
                break;
            }
        }
        int idx = find(v.begin(), v.end(), tmp) - v.begin();
        answer.push_back(idx+1);
    }
    
    return answer;
}