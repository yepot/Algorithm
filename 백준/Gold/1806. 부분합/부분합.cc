#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, s;
    int arr[100005];
    cin >> n >> s;
    for(int i=0; i<n; i++) cin >> arr[i];

    // 재사용하도록 코드짜라!!
    int en = 0;
    int sum = arr[0];
    int min = 0x6fffffff;
    for(int st=0; st<n; st++) {
        while(en<n && sum<s) {
            en++;
            if(en!=n) sum+=arr[en];
        }
        if(en==n) break;
        if(sum>=s && en-st+1<min) min = en-st+1;
        sum-=arr[st];
    }

    if(min==0x6fffffff) min = 0;
    cout << min;
}