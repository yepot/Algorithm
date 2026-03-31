#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    // 정수 값 자체가 우선순위

    int t;
    cin >> t;
    
    for(int i=0; i<t; i++) {
        int k;
        cin >> k;
        multiset<int> ms;

        for(int j=0; j<k; j++) {
            char c;
            int n;
            cin >> c >> n;

            if(c=='I') ms.insert(n);
            else if(ms.size()==0) continue;
            // iterator로 지워!!!!1개만지워야되니까
            else if(c=='D' && n==1) ms.erase(prev(ms.end()));
            else if(c=='D' && n==-1) ms.erase(ms.begin());
            else if(c=='D') ms.erase(ms.find(c));
        }

        if(ms.size()==0) cout << "EMPTY" << '\n';
        else cout << *prev(ms.end()) << ' ' << *ms.begin() << '\n';
    }

}