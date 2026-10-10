#include <string>
#include <vector>
#include <set>

using namespace std;

set<set<int>> s;
set<int> selected;
bool isused[10] = {0, };
vector<string> user, banned;

bool check(string user, string banned) {
    if(user.size() != banned.size()) return 0;
    
    for(int i=0; i<user.size(); i++) {
        if(banned[i] == '*') continue;
        if(banned[i] != user[i]) return 0;
    }
    return 1;
}

void dfs(int depth) {
    
    if(depth == banned.size()) {
        s.insert(selected);
        return;
    }
    
    for(int i=0; i<user.size(); i++) {
        if(isused[i]) continue;
        if(!check(user[i], banned[depth])) continue;
        
        isused[i] = 1;
        selected.insert(i);
        dfs(depth+1);
        isused[i] = 0;
        selected.erase(i);
    }
    
}

int solution(vector<string> user_id, vector<string> banned_id) {
    user = user_id;
    banned = banned_id;
    
    dfs(0);
    
    return s.size();;
}