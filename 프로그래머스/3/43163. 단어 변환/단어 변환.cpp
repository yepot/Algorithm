#include <string>
#include <vector>
#include <queue>

using namespace std;

int dx[2] = {-1, 1};

bool check(string a, string b) {
    int num = a.size();
    
    if(b.size()>a.size()) return false;
    for(int i=0; i<a.size(); i++) {
        if(a[i]==b[i]) num--;
    }
    
    return num==1;
}

int solution(string begin, string target, vector<string> words) {
    
    queue<pair<string, int>> Q;
    bool vis[51] = {false,};
    Q.push({begin, 0});

    while (!Q.empty()) {
        auto cur = Q.front();
        int cnt = cur.second;
        Q.pop();
        
        if(cur.first==target) return cnt;
        
        for (int i=0; i<words.size(); i++) {
            if (!vis[i] && check(cur.first, words[i])) {
                vis[i] = true;
                Q.push({words[i], cnt+1});
            }
        }
    }

    return 0;
}