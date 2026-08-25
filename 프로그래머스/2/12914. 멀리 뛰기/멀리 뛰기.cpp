#include <string>
#include <vector>

using namespace std;

// 1칸 또는 2칸
// DP
// D[i] : i칸 가는 데 필요한 가지 수
// D[i] = D[i-1] + D[i-2]
long long solution(int n) {
    
    long long D[2001];
    D[1] = 1;
    D[2] = 2;
    
    for(int i=3; i<=n; i++) {
        D[i] = (D[i-1] + D[i-2]) % 1234567;
    }
    
    return D[n];
}