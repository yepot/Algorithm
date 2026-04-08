#include <iostream>
#include <algorithm>
#include <list>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    for(int i=0; i<n; i++) {
        string l;
        cin >> l;
        list<char> res;
        auto t = res.begin();
        for(auto i : l) {
            if(i=='<') {
                if(t!=res.begin()) t--;
            }
            else if(i=='>') {
                if(t!=res.end()) t++;
            }
            else if(i=='-') {
                if(t!=res.begin()) {
                    t--;
                    t=res.erase(t);
                }
            }
            else {
                res.insert(t, i);
            }
        }
        for(auto i : res) cout << i;
        cout << '\n';
    }
}