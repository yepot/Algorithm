#include <iostream>
#include <algorithm>
#include <unordered_set>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    unordered_set<string> s;

    for(int i=0; i<n; i++) {
        string a, b;
        cin >> a >> b;
        if(b=="enter") s.insert(a);
        else s.erase(a);
    }
    
    // 남은 애들 정리!
    vector<string> ans(s.begin(), s.end());
    sort(ans.begin(), ans.end(), greater<string>());
    for(auto i : ans) cout << i << '\n';
}