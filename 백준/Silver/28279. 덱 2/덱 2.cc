#include <iostream>
#include <algorithm>
#include <deque>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    deque<int> DQ;
    int n;
    cin >> n;

    int k, x;
    for(int i=0; i<n; i++) {
        cin >> k;
        if(k==1) {
            cin >> x;
            DQ.push_front(x);
        }
        else if(k==2) {
            cin >> x;
            DQ.push_back(x);
        }
        else if(k==3) {
            if(DQ.empty()) cout << -1 << '\n';
            else {
                cout << DQ.front() << '\n';
                DQ.pop_front();
            }
        }
        else if(k==4) {
            if(DQ.empty()) cout << -1 << '\n';
            else {
                cout << DQ.back() << '\n';
                DQ.pop_back();
            }
        }
        else if(k==5) {
            cout << DQ.size() << '\n';
        }
        else if(k==6) {
            if(DQ.empty()) cout << 1 << '\n';
            else cout << 0 << '\n';
        }
        else if(k==7) {
            if(DQ.empty()) cout << -1 << '\n';
            else cout << DQ.front() << '\n';
        }
        else if(k==8) {
            if(DQ.empty()) cout << -1 << '\n';
            else cout << DQ.back() << '\n';
        }
    }
}