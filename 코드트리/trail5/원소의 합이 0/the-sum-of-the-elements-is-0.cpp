#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
    // Please write your code here.
    int n;
    cin >> n;

    unordered_map<int, int> m;
    int a[5001];
    int b[5001];
    int c[5001];
    int d[5001];

    int cnt = 0;

    for(int i=0; i<n; i++) cin >> a[i];
    for(int i=0; i<n; i++) cin >> b[i];
    for(int i=0; i<n; i++) cin >> c[i];
    for(int i=0; i<n; i++) cin >> d[i];

    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            m[a[i]+b[j]]++;
        }
    }

    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            if(m.find(-(c[i]+d[j]))!=m.end()) {
                cnt += m[-(c[i]+d[j])];
            }
        }
    }
    cout << cnt;

    return 0;
}