#include <iostream>
#include <unordered_map>
#include <algorithm>
using namespace std;

int main() {
    // Please write your code here.
    int n;
    cin >> n;

    int max = 0;
    unordered_map<string, int> m;

    for(int i=0; i<n; i++) {
        string str;
        cin >> str;
        sort(str.begin(), str.end());
        m[str]++;
    }

    for(auto i : m) {
        if(i.second > max) max = i.second;
    }

    cout << max;
    return 0;
}