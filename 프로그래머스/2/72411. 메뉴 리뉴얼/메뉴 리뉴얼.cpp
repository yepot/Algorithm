#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

unordered_map<string, int> m;

void dfs(string order, int n, int idx, string cur) {
    if (cur.size() == n) {
        m[cur] ++;
        return;
    }

    for (int i=idx; i<order.size(); i++) {
        cur += order[i];
        dfs(order, n, i+1, cur);
        cur.pop_back();
    }
}

vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;
    
    for(int i=0; i<course.size(); i++) {
        for(int j=0; j<orders.size(); j++) {
            sort(orders[j].begin(), orders[j].end());
            dfs(orders[j], course[i], 0, "");
        }
        
        int max = 0;
        for(auto s : m) {
            if(s.second >= max && s.second >= 2) max = s.second;
        }
        for(auto s : m) {
            if(s.second == max) answer.push_back(s.first);
        }
        
        m.clear();
    }
    
    sort(answer.begin(), answer.end());
    return answer;
}