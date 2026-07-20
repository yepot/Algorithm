#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;

// 숫자, 횟수
bool cmp(pair<int, int> a, pair<int, int> b) {
    if (a.second != b.second) {
        return a.second > b.second; // 횟수 내림차순
    }
    return a.first > b.first; // 횟수가 같으면 숫자 내림차순
}

int main() {
    // Please write your code here.
    int n, k;
    cin >> n >> k;
    unordered_map<int, int> m;
    for(int i=0; i<n; i++) {
        int tmp;
        cin >> tmp;
        m[tmp]++;
    }

    vector<pair<int, int>> v;
    for(auto i : m) {
        v.push_back({i.first, i.second});
    }

    sort(v.begin(), v.end(), cmp);

    for(int i=0; i<k; i++) {
        cout << v[i].first << ' ';
    }

    return 0;
}