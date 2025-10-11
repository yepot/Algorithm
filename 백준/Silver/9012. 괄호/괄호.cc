#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    for(int i=0; i<n; i++) {
        stack<char> S;
        string result = "YES";
        string st;
        cin >> st;
        for(auto c : st) {
            if(c == '(') S.push(c);
            else if(c == ')') {
                if(!S.empty()) S.pop();
                else {
                    result = "NO";
                }
            } 
        }
        if(!S.empty()) result = "NO";
        cout << result << "\n";
    }
}