#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    stack<int> S;
    int cnt = 1;
    for(int i=0; i<n; i++) {
        int x; //입력받을 거 for문 안에 정의!!!
        cin >> x;
        S.push(x);
        
        while(!S.empty() && S.top()==cnt) {
            S.pop();
            cnt++;
        }
    }
    if (S.empty()) cout << "Nice" << '\n';
    else cout << "Sad" << '\n';
}