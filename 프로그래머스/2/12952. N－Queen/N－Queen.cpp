#include <string>
#include <vector>
#include <cmath>

using namespace std;

int answer = 0;
int h[13]; // h[행] = 몇 번째 열에 배치할지 저장

bool check(int depth, int i) {
    for (int idx=0; idx<depth; idx++) {
        if (h[idx] == i) return false;
        if (abs(depth-idx) == abs(i-h[idx])) return false;
    }
    return true;
}

void dfs(int depth, int n) {
    if (depth == n) {
        answer++;
        return;
    }
    
    for (int i=0; i<n; i++) {
        if (check(depth, i)) {
            h[depth] = i;
            dfs(depth+1, n);
        }
    }
}

int solution(int n) {
    
    dfs(0, n);
    return answer;
}