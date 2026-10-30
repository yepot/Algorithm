#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    
    int D[60005] = {0, };
    D[0] = 0;
    D[1] = 1;
    D[2] = 2;
    
    for(int i=3; i<=n; i++) {
        D[i] = D[i-1] + D[i-2];
        D[i] %= 1000000007;
    }
    
    return D[n];
}