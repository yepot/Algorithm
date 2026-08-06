#include <string>
#include <vector>
#include <set>
#include <sstream>

using namespace std;

vector<int> solution(vector<string> operations) {
    vector<int> answer = {0, 0};
    
    multiset<int> ms;
    
    for(auto s : operations) {
        stringstream ss(s);
        string op, num;
        ss >> op >> num;
        
        if(op == "I") {
            ms.insert(stoi(num));
        }
        
        else if(op == "D" && num == "1") {
            if(ms.empty()) continue;
            ms.erase(prev(ms.end()));
        }
        
        else if(op == "D" && num == "-1") {
            if(ms.empty()) continue;
            ms.erase(ms.begin());
        }
    }
    
    if(!ms.empty()) {
        answer[0] = *prev(ms.end());
        answer[1] = *ms.begin();
    }
    return answer;
}