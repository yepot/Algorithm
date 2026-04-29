#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    unordered_map<string, int> m; //종류, 개수
    
    for(int i=0; i<clothes.size(); i++) {
        m[clothes[i][1]]++;
    }

    for(auto s: m) {
        answer *= (s.second+1); // 안입는 경우까지 포함하므로 +1
    }

    return answer-1;
}