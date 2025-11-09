#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int x;
    cin >> x;

    int n = 1;
    while(x-n>0) x-=n++;
    
    if(n%2==1) cout << n-x+1 << "/" << x << '\n';
    else cout << x << "/" << n-x+1 << '\n';

}