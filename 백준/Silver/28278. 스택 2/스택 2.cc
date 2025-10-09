#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    stack<int> S;
    int n;
    cin >> n;

    int k, x;
    for(int i=0; i<n; i++) {
        cin >> k;
        if(k==1) {
            cin >> x;
            S.push(x);
        }
        else if(k==2) {
            if(S.empty()) cout << -1 << '\n';
            else {
                cout << S.top() << '\n';
                S.pop();
            }
        }
        else if(k==3) {
            cout << S.size() << '\n';
        }
        else if(k==4) {
            if(S.empty()) cout << 1 << '\n';
            else cout << 0 << '\n';
        }
        else if(k==5) {
            if(S.empty()) cout << -1 << '\n';
            else cout << S.top() << '\n';
        }
    }
}