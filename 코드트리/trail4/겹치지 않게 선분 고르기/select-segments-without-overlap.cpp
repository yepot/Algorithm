#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
vector<pair<int, int>> arr;
vector<pair<int, int>> lines;
int ans = 0;

void func(int k) {
    if(k == n) {
        if(arr.size() > ans) ans = arr.size();
        return;
    }

    // k번째 선분 선택 X -> 주의!!!!
    func(k+1);

    // k번째 선분 선택 O
    if(arr.empty() || arr.back().second < lines[k].first) {
        arr.push_back(lines[k]);
        func(k+1);
        arr.pop_back();
    }
}

int main() {
    // Please write your code here.
    cin >> n;
    for(int i=0; i<n; i++) {
        int l, r;
        cin >> l >> r;
        lines.push_back({l, r});
    }
    sort(lines.begin(), lines.end());

    func(0);
    cout << ans;

    return 0;
}