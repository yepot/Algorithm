#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;

bool compare(const pair<string, int>& a, const pair<string, int>& b) {
    return a.second < b.second;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int k, l;
    cin >> k >> l;
    unordered_map<string, int> m;

    for(int i=0; i<l; i++) {
        string tmp;
        cin >> tmp;
        m[tmp] = i;
    }

    vector<pair<string, int>> ans(m.begin(), m.end());
    sort(ans.begin(), ans.end(), compare);
    
    int limit = min((int)ans.size(), k);
    for(int i=0; i<limit; i++) cout << ans[i].first << '\n';
}