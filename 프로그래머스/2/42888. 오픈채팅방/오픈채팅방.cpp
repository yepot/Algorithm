#include <string>
#include <vector>
#include <unordered_map>
#include <sstream>

using namespace std;

vector<string> solution(vector<string> record) {
    vector<string> answer;
    
    unordered_map<string, string> m;
    
    for(auto s : record) {
        stringstream ss(s);
        string act, uid, name;
        
        ss >> act >> uid >> name;
        
        if(act != "Leave") {
            m[uid] = name;
        }
    }
    
    for(auto s : record) {
        stringstream ss(s);
        string act, uid, name;
        
        ss >> act >> uid >> name;
        
        if(act == "Enter") {
            answer.push_back(m[uid]+"님이 들어왔습니다.");
        }
        
        else if(act == "Leave") {
            answer.push_back(m[uid]+"님이 나갔습니다.");
        }
    }
    
    return answer;
}