#include <string>
#include <vector>

using namespace std;

string dic = "AEIOU";
int answer = 0;
int cnt = 0;

void dfs(string cur, string target) {
    
    if(cur.length() == 5) return;
    
    for(int i=0; i<5; i++) {
        string next = cur + dic[i];
        cnt++;
        if(next == target) {
            answer = cnt;
            return;
        }
        
        dfs(next, target);
        
        if(answer) return;
    }
}

int solution(string word) {
    
    dfs("", word);
    
    return answer;
}