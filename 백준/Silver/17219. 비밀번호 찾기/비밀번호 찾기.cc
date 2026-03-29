#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    unordered_map<string, string> pw;

    for(int i=0; i<n; i++) {
        string a, b;
        cin >> a >> b;
        pw[a] = b;
    }

    for(int i=0; i<m; i++) {
        string tmp;
        cin >> tmp;
        cout << pw[tmp] << '\n';
    }

}