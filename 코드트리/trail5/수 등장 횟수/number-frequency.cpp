#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
    // Please write your code here.
    int m, n;
    cin >> m >> n;
    unordered_map<int, int> ma;

    for(int i=0; i<m; i++) {
        int tmp;
        cin >> tmp;
        ma[tmp]++;
    }

    for(int i=0; i<n; i++) {
        int tmp;
        cin >> tmp;
        if(ma.find(tmp) == ma.end()) cout << 0 << ' ';
        else cout << ma[tmp] << ' ';

    }

    return 0;
}