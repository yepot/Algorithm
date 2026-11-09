#include <string>
#include <vector>
#include <sstream>
#include <unordered_map>

using namespace std;

vector<string> solution(vector<string> record) {
    vector<string> answer;
    unordered_map<string, string> m;
    vector<pair<string, string>> v;
    
    for(int i=0; i<record.size(); i++) {
        string act, uid, name;
        stringstream ss(record[i]);
        ss >> act >> uid >> name;
        if(act != "Leave") m[uid] = name;
        v.push_back({act, uid});
    }
    
    for(int i=0; i<v.size(); i++) {
        if(v[i].first == "Enter") answer.push_back(m[v[i].second]+"님이 들어왔습니다.");
        else if(v[i].first == "Leave") answer.push_back(m[v[i].second]+"님이 나갔습니다.");                                 
    }
    
    return answer;
}