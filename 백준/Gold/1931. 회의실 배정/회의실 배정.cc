#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    pair<int, int> s[100001];
    int cnt  = 0;
    for(int i=0; i<n; i++) {
        cin >> s[i].second >> s[i].first;
    }
    sort(s, s+n);

    int t = 0;
    for(int i=0; i<n; i++) {
        if(t>s[i].second) continue;
        t = s[i].first;
        cnt++;
    }
    cout << cnt;
}