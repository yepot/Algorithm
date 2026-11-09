#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 동점자는 높은 등수 부여
int main() {
    // Please write your code here.
    int n;
    cin >> n;
    int totalRank[100005] = {0, };
    
    for(int i=0; i<3; i++) {
        vector<pair<int, int>> v;
        int rank[100005] = {0, };
        int score;
        for(int j=0; j<n; j++) {
            cin >> score;
            v.push_back({score, j});
            totalRank[j] += score;
        }
        sort(v.begin(), v.end(), greater<pair<int, int>>());
        for(int j=0; j<n; j++) {
            int cur = v[j].second;
            if(j>0 && v[j].first == v[j-1].first) {
                int prevId = v[j-1].second;
                rank[cur] = rank[prevId];
            }
            else {
                rank[cur] = j + 1;
            }
        }
        for(int j=0; j<n; j++) {
            cout << rank[j] << ' ';
        }
        cout << '\n';
    }

    vector<pair<int, int>> v;
    for(int i=0; i<n; i++) {
        v.push_back({totalRank[i], i});
    }
    sort(v.begin(), v.end(), greater<pair<int, int>>());
    for(int i=0; i<n; i++) {
        int cur = v[i].second;
        if(i!=0 && v[i].first == v[i-1].first) {
            int prevId = v[i-1].second;
            totalRank[cur] = totalRank[prevId];
        }
        else {
            totalRank[cur] = i + 1;
        }
    }
    for(int i=0; i<n; i++) {
        cout << totalRank[i] << ' ';
    }
    cout << '\n';

    return 0;
}