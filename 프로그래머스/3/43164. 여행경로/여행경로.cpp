#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool vis[10001];
bool found = false;
vector<string> answer;

void dfs(string cur, vector<vector<string>>& tickets) {
    
    if(answer.size() == tickets.size()+1) {
        found = true;
        return;
    }
    
    for(int i=0; i<tickets.size(); i++) {
        
        if(tickets[i][0]!=cur || vis[i]) continue;
        
        vis[i] = true;
        answer.push_back(tickets[i][1]);

        dfs(tickets[i][1], tickets);
        
        // 정답 찾았으면 그대로 종료
        if(found) return;
        
        // 실패한 경우에만 원상복구
        answer.pop_back();
        vis[i] = false;
    }
}

vector<string> solution(vector<vector<string>> tickets) {
    
    sort(tickets.begin(), tickets.end());
    
    answer.push_back("ICN");
    dfs("ICN", tickets);

    return answer;
}