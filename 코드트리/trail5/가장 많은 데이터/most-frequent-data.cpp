#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
    // Please write your code here.
    int n;
    cin >> n;
    int max = 0;

    unordered_map<string, int> m;
    for(int i=0; i<n; i++) {
        string tmp;
        cin >> tmp;
        m[tmp]++;
    }

    for(auto i : m) {
        if(i.second > max) max = i.second;
    }

    cout << max;
    return 0;
}