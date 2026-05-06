#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    
    vector<int> V(n+1);
    
    for(int i=0; i<lost.size(); i++) V[lost[i]]--;
    for(int i=0; i<reserve.size(); i++) V[reserve[i]]++;
    
    for(int i=1; i<=n; i++) {
        if(V[i]<0) {
            if(V[i-1]>0 && i-1>0) {
                V[i]++;
                V[i-1]--;
            }
            else if(V[i+1]>0 && i+1<=n) {
                V[i]++;
                V[i+1]--;
            }
        }
    }
    
    for(int i=1; i<=n; i++) {
        if(V[i]>=0) answer++;
    }
    
    return answer;
}