#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    int d[1000001];
    int arr[1000001];
    d[1]=0; arr[1]=0;
    for(int i=2; i<=n; i++) {
        d[i]=d[i-1]+1;
        arr[i]=i-1;
        if(i%3==0) {
            if(d[i]>d[i/3]+1) {
                d[i]=d[i/3]+1;
                arr[i]=i/3;
            }
        }
        if(i%2==0) {
            if(d[i]>d[i/2]+1) {
                d[i]=d[i/2]+1;
                arr[i]=i/2;
            }
        }
    }
    int k=n;
    cout << d[n] << '\n' << n << ' ';
    while(k!=1) {
        cout << arr[k] << ' ';
        k=arr[k];
    }
}