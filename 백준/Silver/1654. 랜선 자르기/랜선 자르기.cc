#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;

int k, n;
int arr[10001];

//랜선의 길이가 k 일 때 n개의 랜선이 가능한가?
bool solve(long long x) {
    long long cnt = 0;
    for(int i=0; i<k; i++) {
        if(arr[i]<x) continue;
        cnt+=arr[i]/x;
    }
    return cnt>=n;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> k >> n;
    for(int i=0; i<k; i++) cin >> arr[i];

    long long st = 1;
    long long en = pow(2,32)-1;
    while(st<en) {
        long long mid = (st+en+1)/2;
        if(solve(mid)) st = mid;
        else en = mid-1;
    }
    cout << st;
}