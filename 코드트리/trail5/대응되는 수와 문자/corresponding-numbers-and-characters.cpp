#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
    // Please write your code here.
    int n, m;
    cin >> n >> m;
    unordered_map<string, string> a;

    for(int i=1; i<=n; i++) {
        string tmp;
        cin >> tmp;
        a[to_string(i)] = tmp;
        a[tmp] = to_string(i);
    }

    for(int i=0; i<m; i++) {
        string tmp;
        cin >> tmp;
        cout << a[tmp] << '\n';
    }

    return 0;
}