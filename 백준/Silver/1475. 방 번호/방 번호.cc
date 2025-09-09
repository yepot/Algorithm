#include <iostream>
#include <cmath>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    int arr[10] = {0};
    while(n>0) {
        arr[n%10]++;
        n/=10;
    }
    arr[6] = arr[9] = (int)ceil((arr[6]+arr[9])/2.0);
    int cnt = 0;
    for(int i=0; i<10; i++) {
        if(arr[i]>cnt) cnt = arr[i];
    }
    cout << cnt << '\n';
}