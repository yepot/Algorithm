#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;

int m, n;
int arr[1000001];

// 이분탐색으로 풀어!!
// 막대 과자의 길이가 x이면 m조각 이상이 나오나
bool solve(int x) {
    if(x==0) return true;
    long long cnt = 0;
    for(int i=0; i<n; i++) cnt+=arr[i]/x;
    return cnt>=m;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> m >> n;
    for(int i=0; i<n; i++) cin >> arr[i];
    sort(arr, arr+n);

    int st = 0;
    int en = arr[n-1];
    
    while(st<en) {
        int mid = (st+en+1)/2;
        if(solve(mid)) st = mid;
        else en = mid-1;
    }
    cout << st;
}