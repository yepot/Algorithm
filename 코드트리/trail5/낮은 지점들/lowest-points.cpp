#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
    // Please write your code here.
    int n;
    cin >> n;

    unordered_map<int, int> m;
    for(int i=0; i<n; i++) {
        int x, y;
        cin >> x >> y;
        if(m.find(x) != m.end()) {
            m[x] = min(y, m[x]);
            continue;
        }
        m[x] = y;
    }

    long long sum = 0;
    for(auto i : m) {
        sum += i.second;
    }

    cout << sum;
    return 0;
}