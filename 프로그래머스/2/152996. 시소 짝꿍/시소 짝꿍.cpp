#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

long long solution(vector<int> weights) {
    long long answer = 0;
    
    // 무게별 몇 명 있는지
    unordered_map<int, long long> m;
    for(int i=0; i<weights.size(); i++) {
        m[weights[i]]++;
    }
    
    // 같은 무게 처리 (& 참조자로 수정해야돼!!! 주의!!!!)
    for(auto& c : m) {
        if(c.second > 1) answer += (c.second*(c.second-1)/2);
    }
    
    for(auto c : m) {
        long long w = c.first;
        long long cnt = c.second;
        
        // c의 3/2배, 2배, 4/3배가 맵에 존재하면 짝꿍 추가
        if(w%2 == 0 && m.count(w*3/2)) answer += cnt*m[w*3/2];
        if(m.count(w*2)) answer += cnt*m[w*2];
        if (w%3 == 0 && m.count(w*4/3)) answer += cnt*m[w*4/3];
    }
    
    return answer;
}