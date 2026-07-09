#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
    // Please write your code here.
    int n, k;
    cin >> n >> k;
    unordered_map<int, int> m;
    int answer = 0;
    
    for(int i=0; i<n; i++) {
        int tmp;
        cin >> tmp;
        m[tmp]++;
    }

    for (auto [num, cnt] : m) {
        if (m.find(k-num) == m.end()) continue;

        // 중복인 수 있는 경우도 생각해!!
        if (num < k-num) {
            answer += cnt*m[k-num];
        } else if (num == k-num) {
            answer += cnt*(cnt-1)/2;
        }
    }
    
    cout << answer;
    return 0;
}