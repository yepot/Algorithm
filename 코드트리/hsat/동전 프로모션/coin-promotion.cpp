#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// D[i] = min(D[i], D[i-현재동전] + 1)
// A: 작은 금액 -> 큰 금액 순서로 채우기
// B: 큰 금액 -> 작은 금액 순서로 채우기 (한번쓸수있으니까!!!!)
int main() {
    // Please write your code here.
    int n, m;
    cin >> n >> m;
    vector<pair<int, char>> v;

    int a;
    char b;
    for(int i=0; i<n; i++) {
        cin >> b >> a;
        v.push_back({a, b});
    }

    int D[100001] = {0, };
    for(int i=0; i<100001; i++) D[i] = 1000000000;
    D[0] = 0;

    for(int i=0; i<v.size(); i++) {
        char t = v[i].second;
        int coin = v[i].first;
        if(t == 'A') {
            for(int j=coin; j<=m; j++) {
                D[j] = min(D[j], D[j-coin] + 1);
            }
        }
        else {
            for(int j=m; j>=coin; j--) {
                D[j] = min(D[j], D[j-coin] + 1);
            }
        }
    }

    if(D[m] == 1000000000) cout << -1;
    else cout << D[m];
    return 0;
}