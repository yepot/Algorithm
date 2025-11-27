#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    int a ,b;
    
    for(int i=0; i<t; i++) {
        cin >> a >> b;
        vector<int> A(a);
        vector<int> B(b);
        for(int j=0; j<a; j++) cin >> A[j];
        for(int j=0; j<b; j++) cin >> B[j];
        sort(A.begin(), A.end());
        sort(B.begin(), B.end());
        int cnt = 0;
        for(int j=0; j<a; j++) {
            for(int k=b-1; k>=0; k--) {
                if(A[j]>B[k]){
                    cnt+=(k+1);
                    break;
                }
            }
        }
        cout << cnt << '\n';
    }

}