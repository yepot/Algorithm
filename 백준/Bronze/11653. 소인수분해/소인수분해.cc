#include <iostream>
using namespace std;


int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;
    int i=2;
    if(n==1) return 0;
    while(n!=1) {
        if(n%i==0) {
            cout << i << '\n';
            n/=i;
        }
        else i++;
    }
}