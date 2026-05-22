#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> citations) {
    int answer = 0;
    
    sort(citations.begin(), citations.end(), greater<>());
    
    for(int h=citations[0]; h>=0; h--) {
        int cnt = 0;
        for(int j=0; j<citations.size(); j++) {
            if(citations[j]>=h) cnt++;
        }
        if(cnt>=h) return h;
    }
    
}