#include <iostream>
#include <algorithm>
#include <math.h>
#include <queue>
using namespace std;

class cmp {
    public:
    bool operator() (int a, int b) {
        if(abs(a)!=abs(b)) return abs(a) > abs(b);
        return a>0 && b<0;
    }
};

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    priority_queue<int, vector<int>, cmp> pq;
    for(int i=0; i<n; i++) {
        int tmp;
        cin >> tmp;
        
        if(tmp==0) {
            if(pq.empty()) cout << '0' << '\n';
            else {
                cout << pq.top() << '\n';
                pq.pop();
            }
        }
        else {
            pq.push(tmp);
        }
    }

}