#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;
    int cnt = 0;

    string s;
    bool b;
    for(int i=0; i<n; i++) {
        cin >> s;

        bool a[26] = {0, };
        a[s[0]-'a'] = 1;
        b = 1;
        for(int j=1; j<s.length(); j++) {
            if(s[j]==s[j-1]) continue;
            if(a[s[j]-'a']) b = 0;
            a[s[j]-'a'] = 1;
        }
        if(b) cnt++;
    }
    cout << cnt << '\n';
}
