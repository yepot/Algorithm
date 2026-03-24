#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n, m;
    int a[100005];
    cin >> n >> m;
    for(int i=0; i<n; i++) cin >> a[i];
    sort(a, a+n);

    int min =  pow(2,32)-1;
    int en = 0;
    for(int st=0; st<n; st++) {
        while(en<n && a[en]-a[st]<m) en++;
        if(en==n) break;
        if(a[en]-a[st]<min) min = a[en]-a[st];
        if(min==m) break;
    } 
    cout << min;
}