#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int k, vector<int> tangerine) {
    int answer = 0;
    
    vector<int> v(10000001, 0);
    
    for(int i=0; i<tangerine.size(); i++) {
        v[tangerine[i]]++;
    }
    
    sort(v.begin(), v.end(), greater<int>());
    
    for(int i=0; i<v.size(); i++) {
        k -= v[i];
        answer++;
        if(k <= 0) break;
    }
    
    return answer;
}